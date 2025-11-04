//#include<iostream>
//#include<string>
//using namespace std;
//class TowerOfHanoi {
//public:
//	void hanoi(int n) {
//		if (n > 0) {
//			f(n, "左", "右", "中");
//		}
//	}
//	void f(int i, const string& from,const string& to, const string& other) {
//		if (i == 1) {
//			cout << "移动圆盘 1 从 " << from << " 到 " << to << endl;
//
//		}
//		else {
//			f(i - 1, from, other, to);
//			cout << "移动圆盘 " << i << " 从 " << from << " 到 " << to << endl;
//			f(i - 1, other, to, from);
//		}
//	}
//};
//int main() {
//	int n = 6;
//	TowerOfHanoi example;
//	example.hanoi(n);
//	return 0;
//}