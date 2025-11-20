#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int t = 0;
        vector<int>height(c,0);
        vector<int>st(c);
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int k = 0; k < c; k++) {
                if (mat[i][k] == 1)height[k]++;
                else height[k] = 0;
            }
            int t = 0;
            int row_ans = 0;
            for (int j = 0; j < c; j++) {
                
                while (t > 0 && height[j] <= height[st[t - 1]]) {
                    int cur = st[--t];
                    if (height[cur] > height[j]) {
                        int left = (t == 0) ? -1 : st[t - 1]; 
                        int len = j - left - 1;             
                        int bottom = max((left == -1) ? 0 : height[left], height[j]); 
                        row_ans += (long long)(height[cur] - bottom) * len * (len + 1) / 2;
                    }
                }
                st[t++] = j;
                
            }
            while (t > 0) {
                int cur = st[--t];
                int left = (t == 0) ? -1 : st[t - 1];
                int len = c - left - 1; 
                int down = (left == -1) ? 0 : height[left];
                row_ans += (long long)(height[cur] - down) * len * (len + 1) / 2;
            }
            ans += row_ans;
        }
        return ans;
    }
};