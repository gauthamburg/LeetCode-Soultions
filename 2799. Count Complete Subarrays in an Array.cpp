class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int> distinct(nums.begin(), nums.end());
        int totalDistinct = distinct.size();

        int count = 0;

        for (int i = 0; i < n; ++i) {
            set<int> seen;
            for (int j = i; j < n; ++j) {
                seen.insert(nums[j]);
                if (seen.size() == totalDistinct) {
                    count++;
                }
            }
        }

        return count;
    }
};
