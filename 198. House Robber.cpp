class Solution {
public:
    int rob(vector<int>& nums) {
        int pre1=0;
        int pre2=0;
        for(auto num : nums){
            int curr=max(pre1,pre2+num);
            pre2=pre1;
            pre1=curr;
        }
        return pre1;
    }
};