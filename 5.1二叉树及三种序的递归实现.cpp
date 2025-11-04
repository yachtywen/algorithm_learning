//#include"iostream"
//using namespace std;
//class TreeNode {
//public:
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int v) :val(v), left(nullptr), right(nullptr){}
//};
//void f(TreeNode* head) {
//    if (head == nullptr) {
//        return;
//    }
//    // 先序
//    f(head->left);
//    // 中序
//    f(head->right);
//    // 后序
//}
////先序打印所有节点（中左右）
//void preOrder(TreeNode* head) {
//	if (!head) return;
//	cout << head->val << " ";
//	preOrder(head->left);
//	preOrder(head->right);
//}
////中序打印所有节点（左中右）
//void inOrder(TreeNode* head) {
//	if (!head) return;
//	inOrder(head->left);
//	cout << head->val<<" ";
//	inOrder(head->right);
//}
////后序打印所有节点（左右中）
//void posOrder(TreeNode* head) {
//	if (!head) return;
//	posOrder(head->left);
//	posOrder(head->right);
//	cout << head->val << " ";
//}
////递归序：任何一个节点在代码中一定会来到三次。
//int main() {
//    TreeNode* head = new TreeNode(1);
//    head->left = new TreeNode(2);
//    head->right = new TreeNode(3);
//    head->left->left = new TreeNode(4);
//    head->left->right = new TreeNode(5);
//    head->right->left = new TreeNode(6);
//    head->right->right = new TreeNode(7);
//
//    preOrder(head);
//    cout << endl;
//    cout << "先序遍历递归版" << endl;
//
//    inOrder(head);
//    cout << endl;
//    cout << "中序遍历递归版" << endl;
//
//    posOrder(head);
//    cout << endl;
//    cout << "后序遍历递归版" << endl;
//
//    return 0;
//}
