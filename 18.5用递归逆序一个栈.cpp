//#include<iostream>
//#include<stack>
//using namespace std;
//int bottomOut(stack<int>& st) {
//	int top = st.top();
//	st.pop();
//	if (st.empty()) {
//		return top;
//	}
//	else {
//		int last = bottomOut(st);
//		st.push(top);
//		return last;
//	}
//}
//void reverse(stack<int>& st) {
//	if (st.empty()) return;
//	int bottom = bottomOut(st);
//	reverse(st);
//	st.push(bottom);
//}