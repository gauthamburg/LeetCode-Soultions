class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> retArr;
        for(int i=0;i<words.size();i++){
           if(contains(words[i],x)){
             retArr.push_back(i);
           }
        }

        return retArr;
    }

    bool contains(string ss,char x){
        if(find(ss.begin(),ss.end(),x)!=ss.end()){
            return true;
        }
        else{
            return false;
        }
    }
};