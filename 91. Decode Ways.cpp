class Solution {
public:
    int numDecodings(string s){
       
       int n=s.size();
       vector<int> dp(n+1,0);

       if(s[0]=='0')return 0;

       dp[0]=1;
       dp[1]=1;

       for(int i=2;i<=n;i++){
        if(s[i-1]!='0'){
            dp[i]+=dp[i-1];
        }

         int curr=stoi(s.substr(i-2,2));
         if(curr>=10 && curr<=26){
            dp[i]+=dp[i-2];
         }
         if(dp[i]==0){
            return 0;
            break;
         }
       }

       return dp[n];







        // int n=s.size();
        // int cnt=1;
        
        // int zcnt=count(s.begin(),s.end(),'0');

        // if(zcnt)cnt=0;

        // if(s[0]=='0')return 0;
        // for(int i=1;i<n;i++){
        //     if(s[i]=='0'){
        //         if(s[i-1]!='1' && s[i-1]!='2'){
        //             return 0;
        //             break;
        //         }
        //     }
        //     if(s[i-1]=='0'){
        //         continue;
        //     }
        //     int curr=stoi(s.substr(i-1,2));
        //     if(curr<27){
        //         cnt++;
        //     }
        // }


        // return cnt;
    }
};