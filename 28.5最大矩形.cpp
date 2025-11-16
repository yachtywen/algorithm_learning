#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int>heights;
    vector<int>st;
    int r;
    int largestArea(int c) {
        r = 0;
        int ans = 0;
        for (int i = 0; i < c; i++) {
            while (r > 0 && heights[st[r - 1]] >= heights[i]) {
                int cur = st[--r];
                int left = (r == 0) ? -1 : st[r - 1];
                ans = max(ans, heights[cur] * (i - left - 1));
            }
            st[r++] = i;
        }
        while (r > 0) {
            int cur = st[--r];
            int left = (r == 0) ? -1 : st[r - 1];
            ans = max(ans, heights[cur] * (c - left - 1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = 0;
        heights.resize(c);
        fill(heights.begin(),heights.begin() + c, 0);
        st.resize(c);
        for (int j = 0; j < r; j++) {
            for (int i = 0; i < c; i++) {
                heights[i] = (matrix[j][i] == '0') ? 0 : heights[i] + 1;       
            }
            ans = max(ans, largestArea(c));
        }
        return ans;
    }
};