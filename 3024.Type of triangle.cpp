class Solution {
public:
    string triangleType(vector<int>& nums) {
        string tri;
        if(nums[0] == nums[1] && nums[1] == nums[2]) {
            tri = "equilateral";
            return tri;
        }

        int cond = 0;
        if(nums[0] + nums[1] > nums[2]) cond++;
        if(nums[0] + nums[2] > nums[1]) cond++;
        if(nums[1] + nums[2] > nums[0]) cond++;

        if(cond != 3) {
            tri = "none";
        } else {
            if(nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2]) {
                tri = "isosceles";
            } else {
                tri = "scalene";
            }
        }

        return tri;
    }
};
