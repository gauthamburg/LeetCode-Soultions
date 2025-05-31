class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> ns;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ns.push_back(s[i]);
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                ns.push_back(s[i] + 32);  
            } else if (s[i] >= '0' && s[i] <= '9') {
                ns.push_back(s[i]);  
            }
        }

        int i = 0;
        int j = ns.size() - 1;
        while (i < j) {
            if (ns[i] != ns[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
