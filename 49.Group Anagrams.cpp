class Solution {
    vector<vector<string>> result;
    vector<unordered_map<int,int>> bighash;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       for(int i=0;i<strs.size();i++){
        unordered_map<int,int> tempHash;
          for(int j=0;j<strs[i].size();j++){
             tempHash[strs[i][j]]++;
          }
          int ind=0;
          for(int j=0;j<bighash.size();j++){
             if(bighash[j]==tempHash){
                result[j].push_back(strs[i]);
                ind=1;
                break;
             }
          }
          if(ind==0){
            bighash.push_back(tempHash);
            result.push_back({strs[i]});
          }
       } 


       return result;  
    }
};