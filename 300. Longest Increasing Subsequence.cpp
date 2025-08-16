class Solution {
public:
    int recsn(int ind,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        if(ind==nums.size())return 0;
        int take,ntake;
        ntake=recsn(ind+1,prev,nums,dp);
        take=INT_MIN;
        if(prev==-1 || nums[ind]>nums[prev]){
            take=1+recsn(ind+1,ind,nums,dp);
        }
        return dp[ind][prev+1]=max(take,ntake);
    }
 
    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
       vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
       return recsn(0,-1,nums,dp);
    }
};