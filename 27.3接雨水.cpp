#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int l = 1, r = height.size() - 2, lmax = height[0], rmax = height[height.size() - 1];
        while (l <= r) {
            if (lmax >= rmax) {
                sum += max(0,rmax- height[r]);
                rmax = height[r] > rmax ? height[r] : rmax;
                r--;
            }
            else {
                sum += max(0, lmax-height[l]);
                lmax = height[l] > lmax ? height[l] : lmax;
                l++;
            }
        }
        return sum;
    }
};