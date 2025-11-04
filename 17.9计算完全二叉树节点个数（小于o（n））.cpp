//#include <iostream>
//#include <cmath>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
//};
//class Solution {
//public:
//    int countNodes(TreeNode* root) {
//        int max_level = runLeft(root);
//        return f(root, max_level);
//    }
//    int f(TreeNode* start,int level) {
//        if (start == nullptr) return 0;
//        int is_level = runLeft(start->right);
//        if (level == is_level + 1) return pow(2, level - 1) + f(start->right, is_level);
//        else return pow(2, is_level) + f(start->left, level - 1);
//    }
//    int runLeft(TreeNode* start) {
//        int level = 0;
//        TreeNode* cur = start;
//        while (cur) {
//            cur = cur->left;
//            level++;
//        }
//        return level;
//    }
//};