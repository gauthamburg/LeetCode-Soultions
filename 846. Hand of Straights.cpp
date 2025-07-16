class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> mp; 
        for (int i : hand) {
            mp[i]++;
        }

        while (!mp.empty()) {
            int start = mp.begin()->first; 
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;
                if (mp[card] == 0) return false;
                mp[card]--;
                if (mp[card] == 0) {
                    mp.erase(card);
                }
            }
        }

        return true;
    }
};
