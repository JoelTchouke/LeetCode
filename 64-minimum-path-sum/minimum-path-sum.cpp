using namespace std;
class Solution {
public:
    unordered_map <long long, int> costs;
    static long long key(int i, int j)
    {
        return ((long long) i << 32 | (unsigned int) j);
    }
    int minimumPathToReach(int i, int j, vector<vector<int>>& grid)
    {
        if (i < 0 || j < 0) return INT_MAX;   // INF (use /2 to avoid overflow)
        if(i == 0 && j == 0)
        {
            return grid[0][0];
        }
        long long k = key(i, j);
        if(costs.find(k) != costs.end())
        {
            return costs[k];
        }
        int answer = grid[i][j] + min(minimumPathToReach(i - 1, j, grid), minimumPathToReach(i, j - 1, grid));
        costs[k] = answer;
        return answer;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int i = grid.size() - 1;
        int j = grid[0].size() - 1;
        return minimumPathToReach(i, j, grid);
    }
};