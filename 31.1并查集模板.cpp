#include<iostream>
#include<vector>
using namespace std;
static const int MAXN = 1000001;
int father[MAXN];
int sz[MAXN];
int stk[MAXN];
int n;
void build() {
	for (int i = 0; i <= n; i++) {
		father[i] = i;
		sz[i] = i;
	}
}
//非递归版
int find(int i) {
	int top = 0;
	while (i != father[i]) {
		stk[top++] = i;
		i = father[i];
	}
	while (top > 0) {
		father[stk[--top]] = i;
	}
	return i;
}
//递归版
//用递归版进行find的同时扁平化可以不使用stack
int find2(int i) {
    if (i != father[i]) {
        father[i] = find2(father[i]);
    }
    return father[i];
}
bool isSameSet(int x, int y) {
	return find(x) == find(y);
}
//有小挂大操作的版本
void unite(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		if (sz[fx] >= sz[fy]) {
			sz[fx] += sz[fy];
			father[fy] = fx;
		}
		else {
			sz[fy] += sz[fx];
			father[fx] = fy;
		}
	}
}
//没有小挂大操作的版本
//此时并查集不需要size数组
void unite2(int x, int y) {
    father[find(x)] = find(y);
}
int main() {
    // ---------------- IO 优化 ----------------
    // 对应 Java 中的 StreamTokenizer 处理
    // 这一步在 C++ 刷题中非常重要，可以显著提高 cin/cout 的速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // -----------------------------------------

    int m;
    // 对应 while(in.nextToken() != StreamTokenizer.TT_EOF)
    // 循环读取 n，直到文件结束
    while (cin >> n) {
        build(); // 根据新的 n 初始化

        cin >> m; // 读取操作次数

        for (int i = 0; i < m; i++) {
            int op, x, y;
            cin >> op >> x >> y;

            if (op == 1) {
                // op == 1: 判断是否同一集合
                // 注意使用 "\n" 替代 endl，endl 会强制刷新缓冲区，速度较慢
                cout << (isSameSet(x, y) ? "Yes" : "No") << "\n";
            }
            else {
                // op == 2: 合并
                unite(x, y);
            }
        }
    }

    return 0;
}