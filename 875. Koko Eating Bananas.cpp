class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxx = INT_MIN;
        long long sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum += piles[i];
            maxx = max(maxx, piles[i]);
        }

        int minn = max(1, (int)((sum + h - 1) / h));  

        return bsrch(piles, h, minn, maxx);
    }

    int bsrch(vector<int>& arr, int h, int l, int r) {
        if (l == r) {
            return l;
        }

        int m = (l + r) / 2;

        if (isOkay(arr, m, h)) {
            return bsrch(arr, h, l, m);
        } else {
            return bsrch(arr, h, m + 1, r);
        }
    }

    bool isOkay(vector<int>& arr, int spe, int hrs) {
        int sum = 0;
        for (auto& i : arr) {
            sum += (i + spe - 1) / spe;  
        }
        return sum <= hrs;
    }
};
