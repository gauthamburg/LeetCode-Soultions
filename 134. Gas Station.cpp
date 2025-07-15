class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas=0,totcost=0;
        int curr=0;
        int tank=0;

        for(int i=0;i<gas.size();i++){
            totgas+=gas[i];
            totcost+=cost[i];
            tank+=(gas[i]-cost[i]);

            if(tank<0){
                curr=i+1;
                tank=0;
            }
        }   

            if(totcost>totgas)return -1;
            else return curr;   
    }
};