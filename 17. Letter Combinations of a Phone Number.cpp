class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 

        vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string current;

        backtrack(result, mapping, digits, current, 0);
        return result;
    }

private:
    void backtrack(vector<string>& result, const vector<string>& mapping, const string& digits, string& current, int index) {
        if (index == digits.size()) { 
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '2'; 
        for (char ch : mapping[digit]) {
            current.push_back(ch);
            backtrack(result, mapping, digits, current, index + 1);
            current.pop_back(); 
        }
    }
};
