//#include<iostream>
//#include<stack>
//using namespace std;
//class SortStackWithRecursive {
//	void sort(stack<int>& st) {
//		int deepCount = deep(st);
//		while (deepCount > 0) {
//			int mx = max(st, deepCount);
//			int k = times(st, deepCount, mx);
//			down(st, deepCount, mx, k);
//			deepCount -= k;
//		}
//	}
//	//确定栈有多少层
//	int deep(stack<int>& st) {
//		if (st.empty()) return 0;
//		int num = st.top();
//		st.pop();
//		int d = deep(st)+1;
//		st.push(num);
//		return d;
//	}
//	//找到最大数
//	int max(stack<int>& st, int deep) {
//		if (deep == 0) return 0;
//		int num = st.top();
//		st.pop();
//		int restMax = max(st, deep - 1);
//		st.push(num);
//		return restMax > num ? restMax : num;
//	}
//	//确定最大值的次数
//	int times(stack<int>& st, int deep, int maxnum) {
//		if (deep == 0)return 0;
//		int num = st.top();
//		st.pop();
//		int restTimes = times(st, deep - 1, maxnum);
//		int t = restTimes + (num == maxnum ? 1 : 0);
//		st.push(num);
//		return t;
//	}
//	//将最大值放入栈底
//	void down(stack<int>& st, int deep, int mx, int k) {
//		if (deep == 0) {
//			for (int i = 0; i < k; i++) {
//				st.push(mx);
//			}
//		}
//		else {
//			int num = st.top();
//			st.pop();
//			down(st, deep - 1, mx, k);
//			if (num != mx) {
//				st.push(num);
//			}
//		}
//	}
//};