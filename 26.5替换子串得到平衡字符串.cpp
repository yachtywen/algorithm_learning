#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int balancedString(string s) {
        vector<int>cnt(4, 0);
        vector<int>map(s.size());
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'Q') map[i] = 0;
            else if (c == 'W') map[i] = 1;
            else if (c == 'E')map[i] = 2;
            else map[i] = 3;
            cnt[map[i]]++;
        }
        int bal = s.size() / 4;
        int debt = 0;
        for (int i = 0; i < 4; i++) {
            if (cnt[i] > bal) {
                cnt[i] = bal - cnt[i];
                debt -= cnt[i];
            }
            else {
                cnt[i] = 0;
            }
        }
        int ans = INT_MIN;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (cnt[map[r]]++ < 0) {
                debt--;
            }
            while (debt == 0) {
                ans = min(ans, r - l + 1);
                if (--cnt[map[l++]] < 0) debt++;
            }
        }
        return ans;
    }
};