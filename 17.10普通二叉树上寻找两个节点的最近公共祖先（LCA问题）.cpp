//#include<iostream>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int v) :val(v), left(nullptr), right(nullptr) {}
//};
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == nullptr || p == root || q == root) return root;
//        TreeNode* l = lowestCommonAncestor(root->left, p, q);
//        TreeNode* r = lowestCommonAncestor(root->right, p, q);
//        if (l != nullptr && r != nullptr) return root;
//        if (l == nullptr && r == nullptr) return nullptr;
//        return l != nullptr ? l : r;
//    }
//};