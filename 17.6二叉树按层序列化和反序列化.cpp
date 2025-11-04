//#include<iostream>
//#include<string>
//#include<vector>
//#include<sstream>
//#include<queue>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int v) :val(v), left(nullptr), right(nullptr) {}
//};
//class Codec {
//public:
//     //Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        string result;
//        queue<TreeNode*> que;
//        if (root == nullptr) return "";
//        que.push(root); 
//        while (!que.empty()) {
//            TreeNode* cur = que.front();
//            que.pop();
//            if (cur != nullptr) {
//                que.push(cur->left);
//                que.push(cur->right);
//                result += to_string(cur->val) + ",";
//            }
//            else result += "#,";
//        }
//        return result;
//    }
//     //Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        if (data.empty()) return nullptr;
//        vector<string> vals = split(data, ',');
//        queue<TreeNode*> que;
//        int cnt = 0;
//        TreeNode* head = generate(vals[cnt++]);
//        que.push(head);
//        while (!que.empty()) {
//            int size = que.size();
//            for (int i = 0; i < size; i++) {
//                TreeNode* cur = que.front();
//                que.pop();
//                if (cnt < vals.size()) cur->left = generate(vals[cnt++]);
//                if (cnt < vals.size()) cur->right = generate(vals[cnt++]);
//                if (cur->left) que.push(cur->left);
//                if (cur->right) que.push(cur->right);
//            }
//        }
//        return head;
//    }
//    vector<string> split(string& data,char delimiter) {
//        vector<string> tokens;
//        string token;
//        stringstream ss(data);
//        while (getline(ss, token, delimiter)) {
//            if (!token.empty())
//                tokens.push_back(token);
//        }
//        return tokens;
//    }
//    TreeNode* generate(string& val) {
//        return val == "#" ? nullptr : new TreeNode(stoi(val));
//    }
//};