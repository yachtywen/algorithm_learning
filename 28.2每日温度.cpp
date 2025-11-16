#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int* st = new int[n];
        vector<int> ans(n, 0);
        int r = 0;
        for (int i = 0; i < n; i++) {
            while(r != 0 && temperatures[i] >= temperatures[st[r-1]]) {
                int cur = st[--r];
                ans[cur] = i;
            }
            st[r++] = i;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ans[i] != 0 && temperatures[ans[i]] == temperatures[i]) {
                ans[i] = ans[ans[i]];
            }
        }
        for (int i = 0; i < n; i++) {
            if(ans[i]!=0)ans[i] -= i;
        }
        return ans;
    }
};