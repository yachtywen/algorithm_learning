#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    static const int MAXN = 100001;
    int deque[MAXN];
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int h = 0 ,t = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            while (h<t && x - k>points[deque[h]][0])h++;
            if (h < t)ans = max(ans, points[deque[h]][1] - points[deque[h]][0] + x + y);
            while (h < t && y-x >= points[deque[t - 1]][1]- points[deque[t - 1]][0])t--;
            deque[t++] = i;
        }
        return ans;
    }
};