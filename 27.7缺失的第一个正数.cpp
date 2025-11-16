#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l < r) {
            if (nums[l] == l + 1)l++;
            else if (nums[l] <= l || nums[l] > r || nums[nums[l] - 1] == nums[l]) {
                swap(nums[l], nums[--r]);
            }
            else {
                swap(nums[l], nums[nums[l]-1]);
            }
        }
        return l + 1;
    }
};