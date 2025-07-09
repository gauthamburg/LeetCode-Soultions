class Solution {
public:
    int recsn(string &text1, string &text2, vector<vector<int>>& dp,int fp,int sp){
        if(fp<0 || sp<0)return 0;

        if(text1[fp]==text2[sp]){
            if(dp[fp][sp]!=-1){
                return dp[fp][sp];
            }
            return dp[fp][sp]=1+recsn(text1,text2,dp,fp-1,sp-1);
        }
        else{
            if(dp[fp][sp]!=-1){
                return dp[fp][sp];
            }
            return dp[fp][sp]=max(recsn(text1,text2,dp,fp-1,sp),recsn(text1,text2,dp,fp,sp-1));
        }


    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));


        return recsn(text1,text2,dp,n-1,m-1);
    }
};