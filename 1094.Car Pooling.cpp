class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int curr=0;
        unordered_map<int,int> ment;
        unordered_map<int,int> mexi;
        
        for(int i=0;i<trips.size();i++){
            if(ment.find(trips[i][1])==ment.end()){
                ment[trips[i][1]]=trips[i][0];
            }
            else{
                ment[trips[i][1]]+=trips[i][0];
            }
            if(mexi.find(trips[i][2])==mexi.end()){
                mexi[trips[i][2]]=trips[i][0];
            }
            else{
                mexi[trips[i][2]]+=trips[i][0];
            }            
        }

        for(int i=0;i<1001;i++){
            curr=curr-mexi[i];
            curr=curr+ment[i];
            if(curr>capacity){
                return false;
                break;
            }
        }

        return true;

    }
};