class Solution {
public:
    int recsn(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& og) {
        if (row < 0 || col < 0) return 0;
        if (og[row][col] == 1) return 0;  // obstacle
        if (row == 0 && col == 0) return 1;  // starting point
        
        if (dp[row][col] != -1) return dp[row][col];
        
        int up = recsn(row - 1, col, dp, og);
        int left = recsn(row, col - 1, dp, og);
        
        return dp[row][col] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recsn(m - 1, n - 1, dp, obstacleGrid);
    }
};
