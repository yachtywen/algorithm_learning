//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//class CountConsistentKeys {
//public:
//	static const int MAXN = 2000001;
//	static const int CHARSET = 12;
//	int tree[MAXN][CHARSET];
//	int pass[MAXN];
//	int cnt = 1;
//	void clear() {
//		for (int i = 0; i <= cnt; i++) {
//			fill(begin(tree[i]), end(tree[i]), 0);
//			pass[i] = 0;
//		}
//	}
//	int path(char c) {
//		//用于隔断进制
//		if (c == '#') return 10;
//		//记录负数的负号
//		if (c == '-') return 11;
//		return c - '0';
//	}
//	int insert(string word) {
//		int cur = 1;
//		pass[cur]++;
//		for (int i = 0; i < word.size(); i++) {
//			int p = path(word[i]);
//			if (tree[cur][p] == 0) {
//				tree[cur][p] = ++cnt;
//			}
//			cur = tree[cur][p];
//			pass[cur]++;
//		}
//	}
//	int count(string pre) {
//		int cur = 1;
//		for (int i = 0; i < pre.size(); i++) {
//			int p = path(pre[i]);
//			if (tree[cur][p] == 0) return 0;
//			cur = tree[cur][p];
//		}
//		return pass[cur];
//	}
//	vector<int> countConsistentKeys(vector<vector<int> >& b, vector<vector<int> >& a) {
//		string builder;
//		for (int i = 0; i < a.size(); i++) {
//			builder.clear();
//			for (int j = 1; j < a[i].size(); j++) {
//				builder += to_string(a[i][j] - a[i][j - 1]) + "#";
//			}
//			insert(builder);
//		}
//		vector<int> ans(b.size());
//		for (int i = 0; i < b.size(); i++) {
//			builder.clear();
//			for (int j = 1; j < b[i].size(); j++) {
//				builder += to_string(b[i][j] - b[i][j - 1]) + "#";
//			}
//			ans[i] = count(builder);
//		}
//		clear();
//		return ans;
//	}
//};