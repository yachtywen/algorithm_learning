#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int mod = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        mod = sum % p;
        if(mod==0)return 0;
        unordered_map<int, int>map;
        int cur = 0;
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            int find = (cur % p - mod + p) % p;
            if (map.count(find)) {
                ans = min(ans, i - map[find]);
            }
            map[cur % p] = i;
        }
        return (ans == nums.size()) ? -1 : ans;
    }
};