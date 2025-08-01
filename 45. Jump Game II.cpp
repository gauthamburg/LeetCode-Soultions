class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,n+1);
        dp[0]=0;
        if(n==1)return 0;
        for(int i=0;i<n;i++){
           for(int j=0;j<=nums[i];j++){
             if(i+j<n){
               dp[i+j]=min(dp[i+j],dp[i]+1);
             }
           }
        }

        return dp[n-1];
    }
};