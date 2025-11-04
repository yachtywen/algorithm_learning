//#include<iostream>
//#include<queue>
//#include<unordered_map>
//#include<vector>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
//};
//class Solution {
//public:
//    vector<vector<int>> levelOrder1(TreeNode* root) {
//        vector<vector<int>> ans;
//        if (root != nullptr) {
//            queue<TreeNode*> q;
//            unordered_map<TreeNode*, int> levels;
//            q.push(root);
//            levels[root] = 0;
//            while (!q.empty()) {
//                TreeNode* cur = q.front();
//                q.pop();
//                int level = levels[cur];
//                if (ans.size() == level) {
//                    ans.push_back({});
//                }
//                ans[level].push_back(cur->val);
//                if (cur->left != nullptr) {
//                    q.push(cur->left);
//                    levels[cur->left] = level + 1;
//                }
//                if (cur->right != nullptr) {
//                    q.push(cur->right);
//                    levels[cur->right] = level + 1;
//                }
//            }
//        }
//        return ans;
//    }
//    vector<vector<int>> levelOrder2(TreeNode* root) {
//
//    }
//};