#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for (int i = 0; i < bookings.size(); i++) {
            int left = bookings[i][0];
            int right = bookings[i][1];
            int num = bookings[i][2];
            ans[left - 1]+=num;
            if(right<n)ans[right] -= num;
        }
        for (int i = 1; i < n; i++) {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};