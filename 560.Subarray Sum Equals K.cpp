class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> ps;
        int sum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ps.push_back(sum);
            if(sum==k){
                cnt++;
            }
        }
        for(int j=0;j<ps.size();j++){
            int diff=ps[j]-k;
            cnt+=occurances(ps,diff,j-1);
        }

        return cnt;
    }

    int occurances(vector<int>& ps,int diff,int last){
        int retval=0;
          for(int i=0;i<=last;i++){
            if(ps[i]==diff){
                retval++;
            }
          }

          return retval;
    }
};