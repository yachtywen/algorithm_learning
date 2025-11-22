#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>deque(n+1,0);
        int h = 0, t = 0;
        vector<long long> sum(n);
        int ans=INT_MAX;
        for (int i = 0; i < n; i++) {
            sum[i+1] += nums[i]+sum[i];
        }
        for (int i = 0; i <= n; i++) {
            while (h < t && sum[i] <= sum[deque[t - 1]])t--;
            deque[t++] = i;
            while (h < t && sum[i] - k >= sum[deque[h]]) {
                ans = min(ans, deque[t-1] - deque[h]);
                h++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};