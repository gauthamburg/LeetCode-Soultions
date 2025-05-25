class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> key;
        vector<int> value;
        for(int i=0;i<nums.size();i++){
            if(find(key.begin(),key.end(),nums[i])!=key.end()){
                continue;
            }
            else{
                key.push_back(nums[i]);
                value.push_back(m[nums[i]]);
            }
        }
        for(int i=0;i<k;i++){
            int maxin=max_element(value.begin(),value.end())-value.begin();
            result.push_back(key[maxin]);
            key.erase(key.begin()+maxin);
            value.erase(value.begin()+maxin);
        }



        return result;
    }
};