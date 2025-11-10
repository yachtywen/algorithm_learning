#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int sum = 0;
        int ans = 0;
        unordered_map<int, int>map;
        map[0] = -1;
        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] > 8)hours[i] = 1;
            else hours[i] = -1;
            sum += hours[i];
            if (map.find(sum - 1) != map.end()) ans = max(i - map[sum - 1], ans);
            else if (sum > 0) ans = i + 1;
            if (map.find(sum) == map.end()) map[sum] = i;
        }
        return ans;
    }
};
