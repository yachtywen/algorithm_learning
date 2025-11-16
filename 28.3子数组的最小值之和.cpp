#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int* st = new int[n];
        int left, right;
        int ans = 0;
        int r = 0;
        int mod = 1000000007;
        for (int i = 0; i < n; i++) {
            while (r != 0 && arr[i] <= arr[st[r - 1]]) {
                int cur = st[--r];
                left = (r == 0) ? -1 : st[r - 1];
                right = i;
                ans += (long long)(cur - left) * (right - cur)*arr[cur]%mod;
            }
            st[r++] = i;
        }
        while (r > 0) {
            int cur = st[--r];
            left = (r == 0) ? -1 : st[r - 1];
            right = arr.size();
            ans += (long long)(cur - left) * (right - cur) * arr[cur] % mod;
        }
        return ans;
    }
};