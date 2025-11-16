#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int r = 0, l = 0; l < houses.size(); l++) {
            while (r < heaters.size() - 1 &&
                abs(houses[l] - heaters[r+1]) >= abs(houses[l] - heaters[r])) {
                r++;
            }
            ans = max(ans, abs(houses[l] - heaters[r]));
        }
        return ans;
    }
};