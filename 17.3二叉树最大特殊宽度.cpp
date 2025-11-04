//#include<iostream>
//#include<algorithm>
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
//    static const int MAXN = 3001;
//    TreeNode* nq[MAXN];
//    unsigned long long iq[MAXN];
//    int l, r;
//    int widthOfBinaryTree(TreeNode* root) {
//        int ans = 1;
//        if (root == nullptr)return 0;
//        l = r = 0;
//        nq[r] = root;
//        iq[r++] = 1;
//        while (l < r) {
//            int size = r - l ;
//            ans = max(ans,(int)(iq[r - 1] - iq[l] + 1));
//            for (int i = 0; i < size;i++) {
//                if (nq[l]->left) {
//                    nq[r] = nq[l]->left;
//                    iq[r++] = iq[l] * 2;
//                }
//                if (nq[l]->right) {
//                    nq[r] = nq[l]->right;
//                    iq[r++] = iq[l] * 2 + 1;
//                }
//                l++;
//            }
//        }
//        return ans;
//    }
//    //方法二（用一个队列）
//    int widthOfBinaryTree(TreeNode* root) {
//        if (root == nullptr) return 0;
//
//        queue<pair<TreeNode*, long long>> q;  
//        q.push(make_pair(root, 0));         
//        int maxWidth = 1;
//
//        while (!q.empty()) {
//            int levelSize = q.size();
//            long long start = q.front().second; 
//            long long end = start;              
//
//            for (int i = 0; i < levelSize; ++i) {
//                
//                pair<TreeNode*, long long> frontPair = q.front();
//                q.pop();
//
//                TreeNode* node = frontPair.first;
//                long long idx = frontPair.second;
//                end = idx;
//
//                long long relativeIdx = idx - start;
//
//                if (node->left != nullptr) {
//                    q.push(make_pair(node->left, 2 * relativeIdx));
//                }
//                if (node->right != nullptr) {
//                    q.push(make_pair(node->right, 2 * relativeIdx + 1));
//                }
//            }
//
//            maxWidth = max(maxWidth, (int)(end - start + 1));
//        }
//
//        return maxWidth;
//    }
//};