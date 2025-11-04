//#include<iostream>
//#include<string>
//using namespace std;
////二维静态数组方式实现前缀树
//static const int MAXN = 150001;
////第二维的大小取决于字符种类数
//int tree[MAXN][26];
//int passCnt[MAXN];
//int endCnt[MAXN];
//int cnt;
//void build() {
//	cnt = 1;
//}
//void insert(string word) {
//	int cur = 1;
//	passCnt[cur]++;
//	for (int i = 0; i < word.size(); i++) {
//		int path = word[i] - 'a';
//		if (tree[cur][path] == 0) {
//			tree[cur][path] = ++cnt;
//		}
//		cur = tree[cur][path];
//		passCnt[cur]++;
//	}
//	endCnt[cur]++;
//}
////查找单词，并最终返回单词个数
//int search(string word) {
//	int cur = 1;
//	for (int i = 0; i < word.size(); i++) {
//		int path = word[i] - 'a';
//		if (tree[cur][path] == 0) {
//			return 0;
//		}
//		cur = tree[cur][path];
//	}
//	return endCnt[cur];
//}
////返回以pre为前缀的单词总共有多少个
//int prefixNumber(string pre) {
//	int cur = 1;
//	for (int i = 0; i < pre.size(); i++) {
//		int path = pre[i] - 'a';
//		if (tree[cur][path] == 0) {
//			return 0;
//		}
//		cur = tree[cur][path];
//	}
//	return passCnt[cur];
//}
////删除一个word
//void erase(string word) {
//	if (search(word) > 0) {
//		int cur = 1;
//		passCnt[cur]--;
//		for (int i = 0; i < word.size(); i++) {
//			int path = word[i] - 'a';
//			if (--passCnt[tree[cur][path] == 0]) {
//				tree[cur][path] = 0;
//			}
//			cur = tree[cur][path];
//		}
//		endCnt[cur]--;
//	}
//}
//void clearTrie() {
//	for (int i = 0; i < cnt; i++) {
//		fill(tree[i], tree[i] + 26, 0);
//		endCnt[i] = 0;
//		passCnt[i] = 0;
//	}
//}