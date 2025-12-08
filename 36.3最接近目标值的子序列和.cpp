#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        long min = 0;
        long max = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                max += nums[i];
            }
            else {
                min += nums[i];
            }
        }
        if (max < goal) {
            return abs(max - goal);
        }
        if (min > goal) {
            return abs(min - goal);
        }
        vector<int>lans;
        vector<int>rans;
        int mid = n / 2;
        f(0, mid, 0, lans, nums);
        f(mid, n, 0, rans, nums);
        sort(lans.begin(), lans.end());
        sort(rans.begin(), rans.end());
        int ans = abs(goal);
        for (int j = rans.size() - 1,i = 0; i < lans.size(); i++) {
            while (j > 0 && abs(goal - rans[j - 1] - lans[i]) <= abs(goal - rans[j] - lans[i])) {
                j--;
            }
            ans = min(ans, abs(goal - lans[i] - rans[j]));
        }
        return ans;
    }
    void f(int i, int e, int s, vector<int>&ans,vector<int>&nums) {
        if (i == e) {
            ans.push_back(s);
            return;
        }
        f(i + 1, e, s, ans, nums);
        f(i + 1, e, s + nums[i], ans, nums);
    }
};