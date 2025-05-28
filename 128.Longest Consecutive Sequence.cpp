class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> us(nums.begin(),nums.end());
       int maxst=0;
       for(auto& num:us){
        int streak=0;
          if(us.find(num-1)==us.end()){
              int curr=num;
              streak=1;

              while(us.find(curr+1)!=us.end()){
                  streak+=1;
                  curr=curr+1;
              }
              maxst=max(maxst,streak);

          }        

       }
       
       return maxst;

    }
};