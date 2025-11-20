#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static const int MAXN = 100001;
    int q[MAXN];
    int h, t;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        h = t = 0;
        int n = nums.size();
        for (int i = 0; i < k - 1; i++) {
            while (h < t && nums[q[t - 1]] <= nums[i])t--;
            q[t++] = i;
        }
        int m = n - k + 1;
        vector<int>ans(m);
        for (int l = 0, r = k - 1; l < m; r++, l++) {
            while (h < t && nums[q[t - 1]] <= nums[r]) {
                t--;
            }
            q[t++] = r;
            ans[l] = nums[q[h]];
            if (q[h] == l) {
                h++;
            }
        }
        return ans;
    }
};