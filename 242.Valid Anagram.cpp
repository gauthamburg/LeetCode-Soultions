class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> ms;
        unordered_map<int,int> mt;
        if(s.size()!=t.size()){
            return false;
        }
        else{
            for(int i=0;i<s.size();i++){
                ms[s[i]]++;
                mt[t[i]]++;
            }
            if(ms==mt){
                return true;
            }
            else{
                return false;
            }
        }
    }
};