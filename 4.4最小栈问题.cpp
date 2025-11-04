//#include"iostream"
//#include"vector"
//using namespace std;
////思路：设置一个最小栈来跟随栈中数值的变化来记录栈中最小值
//class MinStack {
//public:
//	vector<int> s, ms;
//	void push(int val) {
//		if (s.empty()) {
//			s.push_back(val);
//			ms.push_back(val);
//		}
//		else{
//			int min = ms.back() < val ? ms.back() : val;
//		s.push_back(val);
//		ms.push_back(min);
//	}
//}
//	void pop() {
//		s.pop_back();
//		ms.pop_back();
//	}
//	int top() {
//		return s.back();
//	}
//	int getMin() {
//		return ms.back();
//	}
//};
