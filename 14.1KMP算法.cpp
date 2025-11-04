//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//int KMP(string& s1, string& s2) {
//	int n = s1.size();
//	int m = s2.size();
//	if (m == 0) return 0;
//	if (n < m) return -1;
//	vector<int> next = getNextArray(s2);
//	int x = 0, y = 0;
//	while (x < n && y < m) {
//		if (s1[x] = s2[y]) {
//			x++;
//			y++;
//		}
//		else if (y==0) {
//			x++;
//		}
//		else {
//			y = next[y];
//		}
//	}
//	return y == m ? x - y : -1;
//}
//vector<int> getNextArray(string& s) {
//	int m = s.size();
//	if (m == 1) return {-1};
//	vector<int> next(m, 0);
//	next[0] = -1;
//	next[1] = 0;
//	int i = 2;
//	int cn = 0;//当前匹配的前缀长度
//	while (i < m) {
//		if (s[i-1] == s[cn]) {
//			next[i++] = ++cn;
//		}
//		else if (cn > 0) {
//			cn = next[cn];
//		}
//		else {
//			next[i++] = 0;
//		}
//	}
//	return next;
//}
//int main() {
//	string s1 = "abxabcabcaby";
//	string s2 = "abcaby";
//	int pos = KMP(s1, s2);
//	if (pos != -1)
//		cout << "匹配成功，起始下标为: " << pos << endl;
//	else
//		cout << "未匹配到模式串" << endl;
//	return 0;
//}