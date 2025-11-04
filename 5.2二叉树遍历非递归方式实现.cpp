//#include"iostream"
//#include"stack"
//using namespace std;
//class TreeNode {
//public:
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int v):val(v),left(nullptr),right(nullptr){}
//};
////先序遍历
//void preOrder(TreeNode* head) {
//	if (head) {
//		stack<TreeNode*> s;
//		s.push(head);
//		while (!s.empty()) {
//			head = s.top();
//			s.pop();
//			cout << head->val << " ";
//			if (head->right) s.push(head->right);
//			if (head->left) s.push(head->left);
//		}
//		cout << endl;
//	}
//}
////中序遍历
//void inOrder(TreeNode* head) {
//	stack<TreeNode*> s;
//	while (!s.empty() || head) {
//		if (head) {
//			s.push(head);
//			head = head->left;
//		}
//		else {
//			head = s.top();
//			s.pop();
//			cout << head->val << " ";
//			head = head->right;
//		}
//	}
//	cout << endl;
//}
////后序遍历(用两个栈实现)
////思路：中左右->中右左->左右中
//void posOrder(TreeNode* head) {
//	if (head) {
//		stack<TreeNode*> s;
//		stack<TreeNode*> collect;
//		s.push(head);
//		while (!s.empty()) {
//			head = s.top();
//			s.pop();
//			collect.push(head);
//			if (head->left) s.push(head->left);
//			if (head->right) s.push(head->right);
//		}
//		while (!collect.empty()) {
//			cout << collect.top()->val << " ";
//			collect.pop();
//		}
//		cout << endl;
//	}
//}
////后序遍历（用一个栈实现）
//void posOrder2(TreeNode* head) {
//	if (head) {
//		stack<TreeNode*> s;
//		s.push(head);
//		//lastVisted相当于哨兵节点
//		TreeNode* lastVisited = nullptr;
//		while (!s.empty()) {
//			TreeNode* cur = s.top();
//			//左孩子不为空，左右孩子都没处理。
//			if (cur->left && lastVisited != cur->left && lastVisited != cur->right) {
//				s.push(cur->left);
//			}
//			//右孩子不为空，右孩子没处理（但已经处理了左孩子
//			else if (cur->right && lastVisited != cur->right) {
//				s.push(cur->right);
//			}
//			//左右孩子都处理或都为空，打印当前节点并标记为哨兵
//			else {
//				cout << cur->val << " ";
//				lastVisited = cur;
//				s.pop();
//			}
//		}
//		cout << endl;
//	}
//	
//
//}
//int main() {
//		TreeNode* head = new TreeNode(1);
//		head->left = new TreeNode(2);
//		 head->right = new TreeNode(3);
//		head->left->left = new TreeNode(4);
//		head->left->right = new TreeNode(5);
//		head->right->left = new TreeNode(6);
//		head->right->right = new TreeNode(7);
//
//		preOrder(head);
//		cout << "先序遍历非递归版" << endl;
//
//		inOrder(head);
//		cout << "中序遍历非递归版" << endl;
//
//		posOrder(head);
//		cout << "后序遍历非递归版 - 2个栈实现" << endl;
//
//		posOrder2(head);
//		cout << "后序遍历非递归版 - 1个栈实现" << endl;
//
//		return 0;
//	}