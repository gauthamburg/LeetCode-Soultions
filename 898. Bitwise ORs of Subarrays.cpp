class Solution {
public:
    unordered_set<int> res;
    unordered_map<int, unordered_set<int>> memo;

    void recsn(int ind, int sofar, vector<int>& arr) {
        if (ind == arr.size()) return;

        int val = sofar | arr[ind];

        // If already computed this (ind, val), skip
        if (memo[ind].count(val)) return;
        memo[ind].insert(val);

        res.insert(val);
        recsn(ind + 1, val, arr);
    }

    int subarrayBitwiseORs(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            recsn(i, 0, arr);
        }
        return res.size();
    }
};
