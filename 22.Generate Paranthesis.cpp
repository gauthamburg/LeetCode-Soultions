class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr(1,'(');
        recsn(result,curr,n,1);

        return result;   
    }

    void recsn(vector<string>& result,string curr,int n,int ind){
        if(ind==2*n){
            result.push_back(curr);
            return;
        }
        if (isOkay(curr, n, 0)) {
            curr.push_back('(');
            recsn(result, curr, n, ind + 1);
            curr.pop_back();
        }

        if (isOkay(curr, n, 1)) {
            curr.push_back(')');
            recsn(result, curr, n, ind + 1);
            curr.pop_back();
        }
    }

    bool isOkay(string curr,int n,int br){
        if(br==0){
            if(count(curr.begin(),curr.end(),'(')==n){
                return false;
            }
            else{
                return true;
            }
        }
        else if(br==1){
            if(count(curr.begin(),curr.end(),'(')>count(curr.begin(),curr.end(),')')){
                return true;
            }
            else{
                return false;
            }
        }

        return false;
    }
};