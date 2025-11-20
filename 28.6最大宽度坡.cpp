#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int>st(n);
        int t = 0;
        int r = n - 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (t == 0 || nums[i] < nums[st[t - 1]]) {
                st[t++] = i;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            while (t > 0 && nums[st[t - 1]] <= nums[i]) {
                ans = max(ans, i - st[--t]);
            }
        }
        return ans;
    }
};