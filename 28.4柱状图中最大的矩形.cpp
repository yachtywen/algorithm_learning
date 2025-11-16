#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int* st = new int[n];
        vector<vector<int>>min(n, vector<int>(2));
        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r != 0 && heights[i] <= heights[st[r - 1]]) {
                int cur = st[--r];
                min[cur][0] = r == 0 ? -1 : st[r - 1];
                min[cur][1] = i;
            }
            st[r++] = i;
        }
        while (r > 0) {
            int cur = st[--r];
            min[cur][0] = r == 0 ? -1 : st[r - 1];
            min[cur][1] = n;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (min[i][1] - min[i][0]-1));
        }
        return ans;
    }
};