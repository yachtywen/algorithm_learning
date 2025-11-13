#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int len = INT_MIN;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (map.count(s[r]) && map[s[r]] >= l) {
                l = map[s[r]] + 1;
            }
            map[s[r]] = r;            
            len = max(len, r - l + 1);
        }
        return len==INT_MIN?0:len;
    }
};