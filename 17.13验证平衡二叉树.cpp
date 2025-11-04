//#include<iostream>
//#include<cmath>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
//};
//class Solution {
//public:
//    bool balance;
//    bool isBalanced(TreeNode* root) {
//        balance = true;
//        height(root);
//        return balance;
//    }
//    int height(TreeNode* cur) {
//        if (!balance || cur == nullptr) return 0;
//        int lh = height(cur->left);
//        int rh = height(cur->right);
//        if (abs(lh - rh) > 1) balance = false;
//        return max(lh, rh) + 1;
//    }
//};