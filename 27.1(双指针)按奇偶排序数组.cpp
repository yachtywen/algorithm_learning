#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even, odd;
        even = 0;
        odd = 1;
        while (even < nums.size() && odd < nums.size()) {
            if (nums[even] % 2 == 1 && nums[odd] % 2 == 0) {
                int tmp = nums[even];
                nums[even] = nums[odd];
                nums[odd] = tmp;
            }
            if (nums[even] % 2 == 0)even += 2;
            if (nums[odd] % 2 == 1)odd += 2;
        }
        return nums;
    }
};
