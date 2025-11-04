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
//    int yes, no;
//    int rob(TreeNode* root) {
//        f(root);
//        return max(yes, no);
//    }
//    void f(TreeNode* root) {
//        if (root == nullptr) {
//            yes = 0;
//            no = 0;
//            return;
//        }
//        int y = root->val;
//        int n = 0;
//        f(root->left);
//        y += no;
//        n += max(no, yes);
//        f(root->right);
//        y += no;
//        n += max(yes, no);
//        yes = y;
//        no = n;
//    }
//};