//#include<iostream>
//#include<unordered_map>
//using namespace std;
//unordered_map<int, pair<int, int>> mp;
//int setAllValue;
//int setAllTime;
//int cnt;
//void put(int k, int v) {
//	mp[k] = { v,cnt++ };
//}
//void setAll(int v) {
//	setAllTime = cnt++;
//	setAllValue = v;
//}
//int get(int k) {
//	if (!mp.count(k)) return -1;
//	pair<int, int> value = mp[k];
//	int val = value.first;
//	int time = value.second;
//	if (time > setAllTime) {
//		return val;
//	}
//	else {
//		return setAllValue;
//	}
//}
//int main() {
//	int n;
//	while (cin >> n) {
//		setAllValue = 0;
//		setAllTime = -1;
//		cnt = 0;
//		for (int i = 0; i < n; i++) {
//			int op, a, b;
//			cin >> op;
//			if (op == 1) {
//				cin >> a >> b;
//				put(a, b);
//			}
//			else if (op == 2) {
//				cin >> a;
//				cout << get(a);
//				cout << endl;
//			}
//			else if (op == 3) {
//				cin >> a;
//				setAll(a);
//			}
//		}
//	}
//	return 0;
//}