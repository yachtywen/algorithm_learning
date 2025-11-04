//#include<iostream>
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
//    static const int MAXN = 2001;
//    TreeNode* queueArr[MAXN];
//    int l, r;
//    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//        vector<vector<int>> ans;
//        if (root != nullptr) {
//            l = 0;
//            r = 0;
//            int reverse = 1;
//            queueArr[r++] = root;
//            while (l < r) {
//                int size = r - l;
//                vector<int> levels;
//                if (reverse % 2 == 1) {
//                    for (int i = 0,k=l; i < size; i++) {
//                        levels.push_back(queueArr[k++]->val);
//                    }
//                }
//                else {
//                    for (int i = 0, k = r-1; i < size; i++) {
//                        levels.push_back(queueArr[k--]->val);
//                    }
//                }
//                for (int i = 0; i < size; i++) {
//                    TreeNode* cur = queueArr[l++];
//                    if (cur->left) {
//                        queueArr[r++] = cur->left;
//                    }
//                    if (cur->right) {
//                        queueArr[r++] = cur->right;
//                    }
//                }
//                ans.push_back(levels);
//                reverse++;
//            }
//        }
//        return ans;
//
//    }
//};