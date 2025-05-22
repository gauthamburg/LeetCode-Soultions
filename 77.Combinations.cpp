class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        recsn(curr, n, k, 1);  
        return result;
    }

    void recsn(vector<int>& curr, int n, int k, int start) {
        if (curr.size() == k) {
            result.push_back(curr);
            return;
        }
        for (int i = start; i <= n; ++i) {
            curr.push_back(i);
            recsn(curr, n, k, i + 1);
            curr.pop_back();
        }
    }
};
