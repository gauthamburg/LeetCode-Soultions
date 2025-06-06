class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen=0;
        int maxF=0;
        int l=0;
        int r=0;

        vector<int> cnt(26,0);
        while(r<s.size()){
            cnt[s[r]-'A']++;
            maxF=max(maxF,cnt[s[r]-'A']);
            if(((r-l+1)-maxF)<=k){
                maxLen=max(maxLen,r-l+1);
                r++;
                continue;
            }
            else{
                cnt[s[l]-'A']--;
                l++;r++;
            }

        }

        return maxLen;
    }
};