class Solution {
public:
    int recsn(int row,int col,vector<vector<int>>& dp){
        if((row==1 && col==0) || (row==0 && col==1)){ //Base case
            return 1;
        } 
        if(dp[row][col]!=-1)return dp[row][col];
        int res;
        if(col==0)res=recsn(row-1,col,dp);
        else if(row==0)res=recsn(row,col-1,dp);
        else{
            res=recsn(row-1,col,dp)+recsn(row,col-1,dp);
        }
        return dp[row][col]=res;
    }

    int uniquePaths(int m, int n) {
        if(m==1 && n==1)return 1;
        vector<vector<int>> dp(m,(vector<int>(n,-1)));
        //dp[0][1]=1;
        //dp[1][0]=1;       
        return dp[m-1][n-1]=recsn(m-1,n-1,dp);
    }
};