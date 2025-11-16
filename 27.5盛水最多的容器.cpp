#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ans=0;
        int lmax = height[l], rmax = height[r];
        while (l < r) {
            if (ans < (r - l) * min(height[l], height[r])) {
                ans = (r - l) * min(height[l], height[r]);
            }
            if (height[l] < height[r]) {
                while (height[l] <= lmax&& l < r)l++;
                lmax = height[l];
            }
            else {
                while (height[r] <= rmax&&l < r)r--;
                rmax = height[r];
            }
        }
        return ans;
    }
};