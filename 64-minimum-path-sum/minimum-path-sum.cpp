using namespace std;
class Solution {
public:
    int m, n;
    vector<int> memo;
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
        int index = i * n + j;
        if(memo[index] != -1)
        {
            return memo[index];
        }
        int answer = grid[i][j] + min(minimumPathToReach(i - 1, j, grid), minimumPathToReach(i, j - 1, grid));
        
        return memo[index] = answer;
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memo.assign(m * n, -1);
        return minimumPathToReach(m - 1, n - 1, grid);
    }
};