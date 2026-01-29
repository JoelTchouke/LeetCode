class Solution {
public:
    void dfs(vector<vector<int>> &graph, int start, vector <bool> &visitedNodes)
    {
        visitedNodes[start] = true;
        for (int i = 0; i < graph[start].size(); i++)
        {
            if(!visitedNodes[graph[start][i]])
            {
                dfs(graph, graph[start][i], visitedNodes);
            }
        }

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector <vector<int>> graph (n);
        vector <bool> visitedNodes (n, false);
        for (vector<int> node : edges)
        {
            graph[node[0]].push_back(node[1]);
            graph[node[1]].push_back(node[0]);
        }

        int numberOfConnectedComp = 0;

        for(int i = 0; i < n; i++)
        {
            if(visitedNodes[i]) continue;
            dfs(graph, i, visitedNodes);
            numberOfConnectedComp++;
        }

        return numberOfConnectedComp;
        
    }
};