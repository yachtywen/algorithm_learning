//#include"iostream"
//using namespace std;
//class Node {
//public:
//	int data;
//	Node* next;
//    Node(int value):data(value),next(nullptr){}
//};
//class LinkedList {
//public:
//	Node* head;
//	LinkedList() :head(nullptr){}
//	void insertattail(int value) {
//		Node* newNode = new Node(value);
//		if (!head) {
//			head = newNode;
//			return;
//		}
//		Node* temp = head;
//		while (temp->next) {
//			temp = temp->next;
//		}
//		temp->next =newNode ;
//	}
//};
//class Solution {
//public:
//	Node* mergetwolists(Node* head1, Node* head2) {
//		if (!head1 || !head2) {
//			return head1 ? head1 : head2;
//		}
//		Node* head = (head1->data <= head2->data) ? head1 : head2;
//		Node* cur1 = head->next;
//		Node* cur2 = (head == head1) ? head2 : head1;
//		Node* pre = head;
//		while (cur1 && cur2) {
//			if (cur1->data <= cur2->data) {
//				pre->next = cur1;
//				cur1 = cur1->next;
//			}
//			else {
//				pre->next = cur2;
//				cur2 = cur2->next;
//			}
//			pre = pre->next;
//		}
//		pre->next = cur1 ? cur1 : cur2;
//		return head;
//	}
//};
//void printlist(Node* head) {
//	Node* temp = head;
//	while (temp) {
//		cout << temp->data << "->";
//		temp = temp->next;
//	}
//	cout << "nullptr";
//}
//int main() {
//	LinkedList list1;
//	LinkedList list2;
//	list1.insertattail(1);
//	list1.insertattail(2);
//	list1.insertattail(5);
//	list2.insertattail(3);
//	list2.insertattail(4);
//	list2.insertattail(6);
//	Solution solution;
//	Node* merged = solution.mergetwolists(list1.head,list2.head);
//	printlist(merged);
//	return 0;
//}
