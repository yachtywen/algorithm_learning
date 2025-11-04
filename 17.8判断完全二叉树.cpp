//#include<iostream>
//#include<queue>
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int v):val(v),left(nullptr),right(nullptr){}
//};
//class Solution {
//public:
//	bool isCompleteTree(TreeNode* root) {
//		queue<TreeNode*> que;
//		que.push(root);
//		bool start = false;
//		while (!que.empty()) {
//		    TreeNode* cur = que.front();
//			que.pop();
//			if (cur == nullptr) start = true;
//			else {
//				if (start) return false;
//                que.push(cur->left);
//				que.push(cur->right);
//			}
//		}
//		return true;
//	}
//};