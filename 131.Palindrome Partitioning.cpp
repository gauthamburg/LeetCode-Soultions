class Solution {
public:

    vector<vector<string>> result;
   
    bool isPal(string& s){
        int i=0;
        int j=s.size()-1;
        if(j==0)return true;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }

    void recsn(int ind, vector<string>& curr,string& s){
        if(ind==s.size()){
            for(int i=0;i<curr.size();i++){
                if(!isPal(curr[i])){
                    return;
                    break;
                    //return;
                }
            }
            result.push_back(curr);
            return;
        }

        curr.push_back(s.substr(ind,1));
        recsn(ind+1,curr,s);
        curr.pop_back();

        if(ind!=0){
          curr[curr.size()-1].push_back(s[ind]);
          recsn(ind+1,curr,s);
          curr[curr.size()-1].pop_back();           
        }
        // curr[curr.size()-1].push_back(s[ind]);
        // recsn(ind+1,curr,s);
        // curr[curr.size()-1].pop_back();

    }
    
    vector<vector<string>> partition(string s) {
        //int n=s.size();
        int ind=0;
        vector<string> curr;
        recsn(0,curr,s);

        return result;

    }
};