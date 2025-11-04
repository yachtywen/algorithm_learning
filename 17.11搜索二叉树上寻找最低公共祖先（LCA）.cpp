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
//        if (!root) return nullptr;
//        if (root->val > max(p->val, q->val)) return lowestCommonAncestor(root->left, p, q);
//        else if (root->val < min(p->val, q->val)) return lowestCommonAncestor(root->right, p, q);
//        else return root;
//
//    }
//};