//#include"iostream"
//using namespace std;
////用双链表实现双端队列
//class Node {
//public:
//	int data;
//	Node* prev;
//	Node* next;
//	Node(int val) :data(val), next(nullptr),prev(nullptr){}
//};
//class MyCircularDeque {
//public:
//	Node* head;
//	Node* tail;
//	int size;
//	int limit;
//	MyCircularDeque(int length) :size(0), limit(length), head(nullptr), tail(nullptr){}
//	~MyCircularDeque() {
//		while (head) {
//			Node* temp = head;
//			head = head->next;
//			delete temp;
//		}
//	}
//	bool insertFront(int value) {
//		if (isFull()) return false;
//		Node* newNode = new Node(value);
//		if (isEmpty()) {
//			head = tail = newNode;//从右向左赋值
//		}
//		else {
//			newNode->next = head;
//			head->prev = newNode;
//			head = newNode;
//		}
//		size++;
//		return true;
//	}
//	bool insertLast(int value) {
//		if (isFull()) return false;
//		Node* newNode = new Node(value);
//		if (isEmpty()) {
//			head = tail = newNode;
//		}
//		else {
//			newNode->prev = tail;
//			tail->next = newNode;
//			tail = newNode;
//		}
//		size++;
//		return true;
//	}
//	bool deleteFront() {
//		if (isEmpty()) return false;
//		Node* temp = head;
//		//队列中仅有一个元素
//		if (head == tail) {
//			head = tail = nullptr;
//		}
//		else {
//			head = head->next;
//			head->prev = nullptr;
//		}
//		delete temp;
//		size--;
//		return true;
//	}
//	bool deleteLast() {
//		if (isEmpty()) return false;
//		Node* temp = tail;
//		//队列中仅有一个元素
//		if (head == tail) {
//			head = tail = nullptr;
//		}
//		else {
//			tail = tail->prev;
//			tail->next = nullptr;
//		}
//		delete temp;
//		size--;
//		return true;
//	}
//	int getFront() {
//		return isEmpty() ? 0 : head->data;
//	}
//	int getRear() {
//		return isEmpty() ? 0 : tail->data;
//	}
//	bool isEmpty() {
//		return size == 0;
//	}
//	bool isFull() {
//		return size == limit;
//	}
//};
////用数组实现双端队列
//class MyCircularDequeArray {
//public:
//	int length;
//	int l, r, size;
//	//一定要在分配内存空间之前输入具体的大小值。
//	MyCircularDequeArray(int k):length(k),l(0),r(0),size(0){}
//	int* arr = new int[length];
//	
//	//要记住有new必有析构
//	~MyCircularDequeArray() {
//		delete[] arr;  // 释放动态数组
//	}
//	bool insertFront(int value) {
//		if (isFull()) return false;
//		if (l == 0) {
//			l = length - 1;
//			arr[l] = value;
//		}
//		else {
//			arr[--l] = value;
//		}
//		size++;
//		return true;
//	}
//	bool insertLast(int value) {
//		if (isFull()) return false;
//		if (r == length-1) { 
//			r = 0;
//			arr[r] = value;
//			
//		}
//		else {
//			arr[++r] = value;
//		}
//		size++;
//		return true;
//	}
//	bool deleteFront() {
//		if (isEmpty()) return false;
//		if (l == length - 1) l = 0;
//		else l++;
//		size--;
//		return true;
//	}
//	bool deleteLast() {
//		if (isEmpty()) return false;
//		if (r == 0) r = length - 1;
//		else r--;
//		size--;
//		return true;
//	}
//	bool isEmpty() {
//		return size == 0;
//	}
//
//	bool isFull() {
//		return size == length;
//	}
//	int getFront() {
//		return isEmpty() ? -1 : arr[l];
//	}
//
//	int getRear() {
//		return isEmpty() ? -1 : arr[r];
//	}
//};
//int main() {
//	MyCircularDequeArray deque(5);
//
//	deque.insertLast(1);
//	deque.insertLast(2);
//	deque.insertFront(3);
//	deque.insertFront(4);
//
//	cout << "Front: " << deque.getFront() << endl; // 应该输出 4
//	cout << "Rear: " << deque.getRear() << endl;   // 应该输出 2
//
//	deque.deleteFront();
//	cout << "Front after deleteFront: " << deque.getFront() << endl; // 应该输出 3
//	deque.deleteLast();
//	cout << "Rear after deleteLast: " << deque.getRear() << endl;   // 应该输出 1
//
//	return 0;
//}