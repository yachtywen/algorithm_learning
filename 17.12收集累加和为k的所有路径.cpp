//#include<iostream>
//#include<vector>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int v) :val(v), left(nullptr), right(nullptr) {}
//};
//class Solution {
//public:
//    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//        vector<vector<int>> ans;
//        if (root != nullptr) {
//            vector<int> path;
//            dfs(root, targetSum, 0, path, ans);
//        }
//        return ans;
//    }
//    void dfs(TreeNode* cur, int aim, int sum, vector<int>& path, vector <vector<int>>& ans) {
//        if (!cur->left && !cur->right) {
//            if (sum + cur->val == aim) {
//                path.push_back(cur->val);
//                ans.push_back(path);
//                path.pop_back();
//            }
//        }
//        else {
//            path.push_back(cur->val);
//            if (cur->left) dfs(cur->left, aim, sum + cur->val, path, ans);
//            if(cur->right) dfs(cur->right, aim, sum + cur->val, path, ans);
//            path.pop_back();
//        }
//    }
//
//};