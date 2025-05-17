class Solution {
        vector<vector<int>> result;
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> result;
       backtrack(nums,0,result);
       return result;

    }

private:
    void backtrack(vector<int>& nums,int start,vector<vector<int>>& result){

       if(nums.size()==start){
         result.push_back(nums);
         return;
       }
       
       for(int i=start;i<nums.size();i++){
         swap(nums[start],nums[i]);
         backtrack(nums,start+1,result);
         swap(nums[start],nums[i]);
       }
    }
};