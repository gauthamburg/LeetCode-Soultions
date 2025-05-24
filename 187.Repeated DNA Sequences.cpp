#include <unordered_set>
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;
        vector<string> result;

        for (int i = 0; i + 9 < s.size(); ++i) {
            string curr = s.substr(i, 10);
            if (seen.count(curr)) {
                repeated.insert(curr);
            } else {
                seen.insert(curr);
            }
        }

        for (const string& seq : repeated) {
            result.push_back(seq);
        }

        return result;
    }
};
