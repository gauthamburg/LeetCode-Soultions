class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) return "";

        vector<pair<int, string>>& vec = m[key];
        int l = 0, r = vec.size() - 1;
        string res;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (vec[mid].first <= timestamp) {
                res = vec[mid].second;  
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};
