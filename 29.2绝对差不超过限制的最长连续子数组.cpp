#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static const int MAXN = 100001;
    int max_q[MAXN];
    int min_q[MAXN];
    int maxh, maxt, minh, mint;
    int longestSubarray(vector<int>& nums, int limit) {
        maxh = maxt = minh = mint = 0;
        int ans = 0;
        int n = nums.size();
        for (int l = 0, r = 0; r < n; r++) {
            while (maxh<maxt && nums[max_q[maxt - 1]] <= nums[r])maxt--;
            while (minh<mint && nums[min_q[mint - 1]] >= nums[r])mint--;
            max_q[maxt++] = r;
            min_q[mint++] = r;
            while (nums[max_q[maxh]] - nums[min_q[minh]] > limit) {
                l++;
                if (l > max_q[maxh])maxh++;
                if (l > min_q[minh])minh++;
            }
             ans = max(ans, r - l + 1);
        }
        return ans;
    }
};