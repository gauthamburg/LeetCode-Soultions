class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> delta(n + 1, 0); 

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            delta[l]++;
            if (r + 1 < n) delta[r + 1]--;
        }

        vector<int> available(n, 0);
        available[0] = delta[0];
        for (int i = 1; i < n; ++i) {
            available[i] = available[i - 1] + delta[i];
        }

        for (int i = 0; i < n; ++i) {
            if (available[i] < nums[i]) return false;
        }

        return true;
    }
};