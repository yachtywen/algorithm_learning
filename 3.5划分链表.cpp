//#include"iostream"
//using namespace std;
//class Node {
//public:
//	int data;
//	Node* next;
//	Node(int value) :data(value), next(nullptr) {}
//};
//class NodeList {
//public:
//	Node* head;
//	NodeList() :head(nullptr) {}
//	void insertattail(int value) {
//		Node* newNode = new Node(value);
//		while (!head) {
//			head = newNode;
//			return;
//		}
//		Node* temp = head;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		temp->next = newNode;
//	}
//	void printlist() {
//		Node* temp = head;
//		while (temp) {
//			cout << temp->data << " ";
//			temp = temp->next;
//		}
//		cout << endl;
//	}
//};
//class Solution {
//public:
//	static Node* partition(Node* head,int x) {
//		Node* Lefthead = nullptr;
//		Node* Lefttail = nullptr;
//		Node* Righthead = nullptr;
//		Node* Righttail = nullptr;
//		Node* next = nullptr;
//		while (head) {
//			next = head->next;
//			head->next = nullptr;
//			if (head->data < x) {
//				if (!Lefthead) {
//					Lefthead = head;
//					Lefttail = head;
//				}
//				else {
//					Lefttail->next = head;
//					Lefttail = head;
//				}
//			}
//			else {
//				if (!Righthead) {
//					Righthead = head;
//					Righttail = head;
//				}
//				else {
//					Righttail->next = head;
//					Righttail = head;
//				}
//			}
//			head = next;
//		}
//		if (!Lefthead) return Righthead;
//		Lefttail->next = Righthead;
//		return Lefthead;
//	}
//};
//int main() {
//	NodeList list;
//	list.insertattail(1);
//	list.insertattail(4);
//	list.insertattail(3);
//	list.insertattail(2);
//	list.insertattail(5);
//	list.insertattail(2);
//
//	cout << "原始链表: ";
//	list.printlist();
//
//	Solution sol;
//	Node* newHead1 = sol.partition(list.head, 3);
//	Node* newHead2 = Solution::partition(list.head, 3);
//	cout << "分区后链表: ";
//	while (newHead1) {
//		cout << newHead1->data << " ";
//		newHead1 = newHead1->next;
//	}
//	cout << endl;
//	while (newHead2) {
//		cout << newHead2->data << " ";
//		newHead2 = newHead2->next;
//	}
//	return 0;
//}