//#include"iostream"
//#include"vector"
//using namespace std;
////用栈来实现队列
//class MyQueue {
//public:
//	vector<int>in, out;
//	//从in栈把数据倒出out栈
//	//out栈空了才能倒入数据
//	//如果倒数据，in栈数据必须要全部倒空
//	void IntoOut() {
//		if (out.empty()) {
//			while (!in.empty()) {
//				out.push_back(in.back());
//				in.pop_back();
//			}
//		}
//	}
//	//在队列尾部加入数据
//	void push(int x) {
//		in.push_back(x);
//		IntoOut();
//	}
//	//弹出，且返回队列头部的元素
//	int pop() {
//		IntoOut();
//		int val = out.back();
//		out.pop_back();
//		return val;
//	}
//	//不弹出，返回队列头部的元素
//	int peek() {
//		IntoOut();
//		return out.back();
//	}
//	//检测队列是否为空
//	bool empty() {
//		return in.empty() && out.empty();
//	}
//};
////用队列来实现栈
//class MyStack {
//public:
//	vector<int> s;
//	//在栈中加入元素
//	void push(int x) {
//		s.push_back(x);
//		for (int i = 0; i < s.size() - 1; i++) {
//			s.push_back(s.front());
//			s.erase(s.begin());
//		}
//	}
//	//弹出栈最上面的元素
//	int pop() {
//		int val = s.front();
//		s.erase(s.begin());
//		return val;
//	}
//	//获取栈顶元素但是不弹出
//	int top() {
//		return s.front();
//	}
//	//判断栈是否为空
//	bool empty() {
//		return s.empty();
//	}
//};
