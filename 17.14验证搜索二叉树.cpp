//#include<iostream>
//#include<cmath>
//#include<stack>
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
//    //使用递归调用版本
//    stack<TreeNode*> s;
//    bool isValidBST(TreeNode* root) {
//        inOrder(root);
//        while (!s.empty()) {
//            TreeNode* cur = s.top();
//            s.pop();
//            if (!s.empty()&&cur->val <= s.top()->val) {
//                return false;
//            }
//        }
//        return true;
//    }
//    void inOrder(TreeNode* cur) {
//        if (cur == nullptr) return;
//        inOrder(cur->left);
//        s.push(cur);
//        inOrder(cur->right);
//    }
//    //使用非递归遍历来实现
//    stack<TreeNode*> s;
//    static const int MAXN = 10001;
//    int arr[MAXN];
//    int cnt=0;
//    void inOrder(TreeNode* cur) {
//        while (!s.empty() || cur) {
//            if (cur) {
//                s.push(cur);
//                cur = cur->left;
//            }
//            else {
//                cur = s.top();
//                s.pop();
//                arr[cnt++] = cur->val;
//                cur = cur->right;
//            }
//        }
//    }
//};