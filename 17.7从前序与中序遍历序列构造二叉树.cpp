//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int value):val(value),left(nullptr),right(nullptr){}
//};
//class Solution {
//public:
//	TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
//		if (pre.empty() || in.empty() || pre.size() != in.size()) return nullptr;
//		unordered_map<int, int> map;
//		for (int i = 0; i < in.size(); i++) {
//			map[in[i]] = i;
//		}
//		return f(pre, 0, pre.size() - 1, in, 0, in.size() - 1, map);
//	}
//	TreeNode* f(vector<int>& pre, int l1, int r1, vector<int>& in, int l2, int r2, unordered_map<int, int>& map) {
//		if (l1 > r1) return nullptr;
//		TreeNode* head = new TreeNode(pre[l1]);
//		if (l1 == r1)return head;
//		int headnum = map[pre[l1]];
//		head->left = f(pre, l1 + 1, l1 + headnum - l2, in, l2, headnum - 1, map);
//		head->right = f(pre, l1 + headnum - l2 + 1, r1, in, headnum + 1, r2, map);
//		return head;
//	}
//};