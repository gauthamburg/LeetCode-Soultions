class Solution {
    unordered_map<string, string> longToShort;
    unordered_map<string, string> shortToLong;
    string base = "http://tinyurl.com/";
    int id = 0;

public:
    string encode(string longUrl) {
        if (longToShort.find(longUrl) != longToShort.end()) {
            return longToShort[longUrl];
        }

        string shortUrl = base + to_string(id++);
        longToShort[longUrl] = shortUrl;
        shortToLong[shortUrl] = longUrl;

        return shortUrl;
    }

    string decode(string shortUrl) {
        return shortToLong[shortUrl];
    }
};
