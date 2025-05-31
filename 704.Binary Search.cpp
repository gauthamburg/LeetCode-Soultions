class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySrch(nums, target, 0, nums.size() - 1);
    }

    int binarySrch(vector<int>& nums, int tar, int left, int right) {
        if (left > right) {
            return -1;
        }

        int mid = (left + right) / 2;

        if (tar == nums[mid]) {
            return mid;
        }
        else if (tar < nums[mid]) {
            return binarySrch(nums, tar, left, mid - 1);  
        }
        else {
            return binarySrch(nums, tar, mid + 1, right);
        }
    }
};
