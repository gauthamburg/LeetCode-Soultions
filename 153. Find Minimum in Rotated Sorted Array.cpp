class Solution {
public:
    int findMin(vector<int>& nums) {
        return nums[bsrch(nums, 0, nums.size() - 1)];
    }

    int bsrch(vector<int>& nums, int l, int r) {
        if (l == r) {
            return l;
        }

        int m = (l + r) / 2;

        if (nums[m] < nums[r]) {
            return bsrch(nums, l, m);
        } else {
            return bsrch(nums, m + 1, r);
        }
    }
};
