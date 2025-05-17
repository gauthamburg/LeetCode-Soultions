class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            bool found = false;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == 0) {
                    swap(nums[i], nums[j]);
                    i++;
                    found = true;
                    break;  
                }
            }
            if (!found) break; 
        }

        int cnt0 = count(nums.begin(), nums.end(), 0);
        int k = cnt0;
        while (k < nums.size()) {
            bool found = false;
            for (int y = k; y < nums.size(); y++) {
                if (nums[y] == 1) {
                    swap(nums[k], nums[y]);
                    k++;
                    found = true;
                    break;
                }
            }
            if (!found) break; 
        }
    }
};
