//#include"iostream"
//using namespace std;
//class Node {
//public:
//	int data;
//	Node* next;
//	Node(int value):data(value),next(nullptr){}
//};
//class NodeList {
//public:
//	Node* head;
//	NodeList() :head(nullptr){}
//	void insertathead(int value) {
//		Node* newNode = new Node(value);
//		newNode->next = head;
//		head = newNode;
//	}
//	void insertattail(int value) {
//		Node* newNode = new Node(value);
//		while (!head) {
//			head = newNode;
//			return;
//		}
//		Node* temp = head;
//		while (temp->next!=nullptr) {
//			temp = temp->next;
//		}
//		temp->next = newNode;
//	}
//	void printlist() {
//		Node* temp = head;
//		while (temp) {
//			cout << temp->data<<" ";
//			temp = temp->next;
//		}
//	}
//	~NodeList() {
//		Node* temp;
//		while(head) {
//			temp = head;
//			head = head->next;
//			delete temp;
//		}
//	}
//};
//class Solution {
//public:
//	Node* reverselist(Node* head) {
//		Node* pre = nullptr;
//		Node* next = nullptr;
//		while (head != nullptr) {
//			next = head->next;
//			head->next = pre;
//			pre = head;
//			head = next;
//		}
//		return pre;
//	}
//};
//int main() {
//	NodeList list;
//	Solution solution;
//	list.insertattail(1);
//	list.insertattail(2); 
//	list.insertattail(3);
//	list.insertattail(4);
//	list.printlist();
//	list.head=solution.reverselist(list.head);
//	list.printlist();
//	return 0;
//}