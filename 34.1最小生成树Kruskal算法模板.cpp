#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//  ±º‰∏¥‘”∂»O(n + m) + O(m * log m)
const int MAXN = 5001;
const int MAXM = 200001;
struct edge {
	int u, v, w;
}edges[MAXM];
int father[MAXN];
int n,m;
void build() {
	for (int i = 0; i <= n; i++) {
		father[i] = i;
	}
}
int find(int i) {
	if (father[i] != i) {
		father[i] = find(father[i]);
	}
	return father[i];
}
bool unite(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		father[fx] = fy;
		return true;
	}
	else {
		return false;
	}
}
int main() {
	cin >> n >> m;
	build();
	for (int i = 0; i < m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}
	sort(edges, edges + m, [](edge& a, edge& b) {
		return a.w < b.w;
		});
	int ans = 0;
	int edgeCnt = 0;
	for (int i = 0; i < m ; i++) {
		if (unite(edges[i].u, edges[i].v)) {
			edgeCnt++;
			ans += edges[i].w;
		}
	}
	if (edgeCnt == n - 1)cout << ans;
	else cout << "orz";
	return 0;
}