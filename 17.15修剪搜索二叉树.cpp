//#include <iostream>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
//};
//class Solution {
//public:
//    TreeNode* trimBST(TreeNode* root, int low, int high) {
//        if (root == nullptr) return nullptr;
//        if (root->val > high) return trimBST(root->left, low, high);
//        if (root->val < low) return trimBST(root->right, low, high);
//        else {
//            root->left = trimBST(root->left, low, high);
//            root->right = trimBST(root->right, low, high);
//            return root;
//        }
//    }
//};