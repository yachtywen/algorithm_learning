//#include<iostream>
//#include<string>
//#include<vector>
//#include<sstream>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int v) :val(v), left(nullptr), right(nullptr) {}
//};
//class Codec {
//public:
//    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        string result;
//        f(root, result);
//        return result;
//    }
//    void f(TreeNode* root, string& builder) {
//        if (root == nullptr) builder += "#,";
//        else {
//            builder += to_string(root->val) + ",";
//            f(root->left, builder);
//            f(root->right, builder);
//        }
//    }
//    // Decodes your encoded data to tree.
//    int cnt;
//    TreeNode* deserialize(string data) {
//        vector<string> vals = split(data, ',');
//        cnt = 0;
//        return g(vals);
//    }
//    TreeNode* g(vector<string> vals) {
//        if (cnt >= (int)vals.size()) return nullptr;
//        string cur = vals[cnt++];
//        if (cur == "#" || cur.empty()) return nullptr;
//        else {
//            TreeNode* newTreeNode = new TreeNode(stoi(cur));
//            newTreeNode->left = g(vals);
//            newTreeNode->right = g(vals);
//            return newTreeNode;
//        }
//    }
//    vector<string> split(string& data, char delimiter) {
//        vector<string> tokens;
//        string token;
//        stringstream ss(data);
//        while (getline(ss, token, delimiter)) {
//            tokens.push_back(token);
//        }
//        return tokens;
//    }
//};