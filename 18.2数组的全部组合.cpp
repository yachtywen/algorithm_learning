//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        vector<vector<int>> ans;
//        sort(nums.begin(), nums.end());
//        vector<int> path(nums.size());
//        f(nums, 0, path, 0, ans);
//        return ans;
//    }
//    void f(vector<int>& nums, int i, vector<int>& path,int size,vector<vector<int>>& ans) {
//        if (i == nums.size()) {
//            vector<int> cur(path.begin(), path.begin() + size);
//            ans.push_back(cur);
//            return;
//        }
//        else {
//            int j = i + 1;
//            while (j < nums.size() && nums[i] == nums[j]) {
//                j++;
//            }
//            f(nums, j, path, size, ans);
//            for (int k = i; k < j; k++) {
//                path[size++] = nums[k];
//                f(nums, j, path, size, ans);
//            }
//        }
//    }
//};