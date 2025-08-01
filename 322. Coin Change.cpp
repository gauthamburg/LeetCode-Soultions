class Solution {
public:
    int recsn(int ind, int left, vector<int>& coins, vector<vector<int>>& dp) {
        if (left == 0) return 0;
        if (ind < 0) return 1e9;

        if (dp[ind][left] != -1) return dp[ind][left];

        int take = 1e9;
        if (coins[ind] <= left) {
            take = 1 + recsn(ind, left - coins[ind], coins, dp); 
        }
        int nottake = recsn(ind - 1, left, coins, dp);

        return dp[ind][left] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int res = recsn(coins.size() - 1, amount, coins, dp);
        return (res == 1e9) ? -1 : res;
    }
};
