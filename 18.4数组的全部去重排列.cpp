//#include<iostream>
//#include<vector>
//#include<unordered_set>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<vector<int>> ans;
//        f(nums, 0, ans);
//        return ans;
//    }
//    void f(vector<int>& nums, int i, vector<vector<int>>& ans) {
//        if (i == nums.size()) {
//            ans.push_back(nums);
//            return;
//        }
//        else {
//            unordered_set<int> unique_element;
//            for (int j = i; j < nums.size(); j++) {
//                if (!unique_element.count(nums[j])) {
//                    unique_element.insert(nums[j]);
//                    swap(nums[i], nums[j]);
//                    f(nums, i + 1, ans);
//                    swap(nums[i], nums[j]);
//                }
//            }
//        }
//    }
//};