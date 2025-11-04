//#include"iostream"
//using namespace std;
////创建节点
//class Node {
//public:
//	int data;
//	Node* next;
//	Node(int val):data(val),next(nullptr){}
//};
//
//class LinkedList {
//public:
//	Node* head;
//	LinkedList() :head(nullptr) {}
//	//在头部插入新节点
//	void insertathead(int value) {
//		Node* newNode =new Node(value);
//		newNode->next = head;
//		head = newNode;
//	}
//	//在尾部插入新节点
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
//		temp->next = newNode;
//	}
//	void deletetheNode(int value) {
//		if (!head) return;
//		//删除头节点
//		if (head->data == value) {
//			Node* temp = head;
//			head = head->next;
//			delete temp;
//			return;
//		}
//		//删除中间某个节点
//		Node* temp = head;
//		while (temp->next && temp->next->data != value) {
//			temp = temp->next;
//		}
//		if (temp->next) {
//			Node* toDelete = temp->next;
//			temp->next = temp->next->next;
//			delete toDelete;
//		}
//	}
//	//打印链表
//	void printlist() {
//		Node* temp = head;
//		while (temp) {
//			cout << temp->data << " ";
//			temp = temp->next;
//		}
//		cout << endl;
//	}
//	//析构函数（释放内存）
//	~LinkedList() {
//		Node* temp;
//		while (head) {
//			temp = head;
//			head = head->next;
//			delete temp;
//		}
//	}
//};
//int main() {
//	LinkedList list;
//	list.insertathead(10);
//	list.insertathead(20); 
//	list.insertathead(30);
//	list.printlist();
//	list.deletetheNode(10);
//	list.deletetheNode(20);
//	list.printlist();
//	list.insertattail(20);
//	list.printlist();
//	return 0;
//}