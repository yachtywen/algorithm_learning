//#include"iostream"
//#include"vector"
//using namespace std;
////用数组实现队列
//class queue1 {
//public:
//	vector<int> queue;
//	int l, r;
//	queue1(int length) :queue(length), l(0), r(0){}
//	bool isEmpty() {
//	//如果l=r那么是true返回的也是true，这样写更简洁。	
//		return l == r;
//	}
//	void offer(int num) {
//		queue[r++] = num;
//	}
//	//弹出
//	int poll() {
//		return queue[l++];
//	}
//	int head() {
//		return queue[l];
//	}
//	int tail() {
//		return queue[r - 1];
//	}
//	int size() {
//		return r - l;
//	}
//};
////用数组实现栈
//class stack1 {
//public:
//	vector<int> stack;
//	int size;
//	stack1(int length) :stack(length), size(0){}
//	bool isEmpty() {
//		return size == 0;
//	}
//	void push(int num) {
//		stack[size++] = num;
//	}
//	int pop() {
//		return stack[--size];
//	}
//	int peek() {
//		return stack[size - 1];
//	}
//	int getSize() {
//		return size;
//	}
//};
////用数组实现循环队列
//class CircularQueue {
//public:
//	vector<int> queue;
//	int l, r, size, limit;
//	CircularQueue(int length):queue(length),l(0),r(0),size(0),limit(length){}
//	bool enQueue(int value) {
//		if (isFull()) {
//			return false;
//		}
//		queue[r] = value;
//		r = (r + 1) % limit;
//		size++;
//		return true;
//	}
//	bool deQueue() {
//		if (isEmpty()) {
//			return false;
//		}
//		l = (l + 1) % limit;
//		size--;
//		return true;
//	}
//	int Front() {
//		return isEmpty() ? -1 : queue[l];
//	}
//	int Rear() {
//		return isEmpty() ? -1 : queue[(r - 1 + limit) % limit];
//	}
//	bool isEmpty() {
//		return size == 0;
//	}
//
//	bool isFull() {
//		return size == limit;
//	}
//};