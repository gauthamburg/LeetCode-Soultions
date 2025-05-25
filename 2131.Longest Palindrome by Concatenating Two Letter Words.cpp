class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        int cnt=0;
        bool flag = false;

        for(auto& word : words){
            string rev=word;
            reverse(rev.begin(),rev.end());
            if(m[rev]>0){
                cnt=cnt+4;
                m[rev]--;
            }
            else{
                m[word]++;
            }

        }
        for (auto& [word, freq] : m) {
            if (word[0] == word[1] && freq > 0) {
                flag = true;
                break;
            }
        }

        if (flag) {
            cnt += 2; 
        }

        return cnt;
    }
};