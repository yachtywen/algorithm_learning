//#include<iostream>
//#include<queue>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int v) :val(v), left(nullptr), right(nullptr) {}
//};
//class Solution {
//public:
//    int maxDepth(TreeNode* root) {
//        return root == nullptr ? 0 : max(maxDepth(root->left),maxDepth( root->right)) + 1;
//    }
//    int minDepth(TreeNode* root) {
//        if (root == nullptr) return 0;
//        if (root->left == nullptr && root->right == nullptr) {
//            return 1;
//        }
//        int ldeep = INT_MAX;
//        int rdeep = INT_MAX;
//        if (root->left) ldeep = minDepth(root->left);
//        if (root->right) rdeep = minDepth(root->right);
//        return min(ldeep, rdeep)+1;
//    }
//    int minDepth(TreeNode* root) {
//        queue<TreeNode*> que;
//        if (root == nullptr) return 0;
//        int depth = 1;
//        que.push(root);
//        while (!que.empty()) {
//            int size = que.size();
//            for (int i = 0; i < size; i++) {
//                TreeNode* cur = que.front();
//                que.pop();
//                if (cur->right) que.push(cur->right);
//                if (cur->left) que.push(cur->left);
//                if (cur->left == nullptr && cur->right == nullptr) return depth;
//            }
//            depth++;
//        }
//    }
//};