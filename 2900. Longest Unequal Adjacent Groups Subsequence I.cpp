class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        if (words.size() == 1) {
            return words;
        }

        int n = words.size();
        vector<string> result;

        result.push_back(words[0]);
        int lastGroup = groups[0];

        for (int i = 1; i < n; i++) {
            if (groups[i] != lastGroup) {
                result.push_back(words[i]);
                lastGroup = groups[i];
            }
        }
        
        return result;
    }
};