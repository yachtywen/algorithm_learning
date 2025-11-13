#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>cnt(256, 0);
        for (char c : t) {
            cnt[c]--;
        }
        int debt = t.size();
        int len = INT_MAX;
        int start = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (cnt[s[r]]++ < 0) debt--;
            while (debt == 0) {
                while (cnt[s[l]] > 0) {
                    cnt[s[l++]]--;
                }
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    start = l;
                }
                cnt[s[l]]--;
                l++;
                debt++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
