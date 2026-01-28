using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> costMap(m, vector<int>(n, 0));
        costMap[0][0] = grid[0][0];
        for(int i = 1; i < m; i++)
        {
            costMap[i][0] = costMap[i - 1][0] + grid[i][0];
        }
        for(int j = 1; j < n; j++)
        {
            costMap[0][j] = costMap[0][j - 1] + grid[0][j];
        }

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                costMap[i][j] = grid[i][j] + min(costMap[i - 1][j], costMap[i][j - 1]);
            }
        }
        return costMap[m - 1][n - 1];

    }
};