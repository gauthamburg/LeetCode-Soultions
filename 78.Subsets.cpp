class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> second;
        priSbst(nums,result,second,0);
        return result;
    }

    void priSbst(vector<int>& nums,vector<vector<int>>& result,vector<int>& second,int i){
            if(i==nums.size()){
                result.push_back(second);
                return;
            }
            second.push_back(nums[i]);
            priSbst(nums,result,second,i+1);
            second.pop_back();
            priSbst(nums,result,second,i+1);           
    }
};