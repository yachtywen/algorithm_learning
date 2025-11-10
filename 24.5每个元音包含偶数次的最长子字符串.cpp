#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findTheLongestSubstring(string s) {
        //u o i e a
        vector<int>map(32, -2);
        map[0] = -1;
        int ans = 0;
        int status = 0;
        for (int i = 0; i < s.length(); i++) {
            int m;
            switch (s[i]) {
            case 'a': m = 0; break;
            case 'e': m = 1; break;
            case 'i': m = 2; break;
            case 'o': m = 3; break;
            case 'u': m = 4; break;
            default:  m = -1; break;
            }
            if (m != -1) {
                status ^= (1 << m);
            }
            if (map[status] != -2) {
                ans = max(ans, i - map[status]);
            }
            else {
                map[status] = i;
            }
        }
        return ans;
    }
};