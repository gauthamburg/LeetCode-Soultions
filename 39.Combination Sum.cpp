class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        recsn(curr, 0, target, candidates);
        return result;
    }

    void recsn(vector<int>& curr, int ind, int tar, vector<int>& candidates) {
        int sum = accumulate(curr.begin(), curr.end(), 0);

        if (sum == tar) {
            result.push_back(curr);
            return;
        }

        if (sum > tar) return;

        for (int i = ind; i < candidates.size(); i++) {  
            curr.push_back(candidates[i]);
            recsn(curr, i, tar, candidates);  
            curr.pop_back();
        }
    }
};
