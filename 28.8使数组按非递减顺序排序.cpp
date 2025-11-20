#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static const int MAXM = 100001; 
    int s[MAXM][2];          
    int size;
    int totalSteps(vector<int>& nums) {
        size = 0;
        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int curTurns = 0;
            while (size > 0 && s[size - 1][0] < nums[i]) {
                curTurns = max(curTurns + 1, s[--size][1]);
            }
            s[size][0] = nums[i];
            s[size++][1] = curTurns;
            ans = max(ans, curTurns);
        }
        return ans;
    }
};