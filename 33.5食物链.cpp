#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 5001;
const int MAXM = 500001;
const int MOD = 80112002;
int head[MAXN], nxt[MAXM], to[MAXM];
int cnt = 1;
int indegree[MAXN];
int lines[MAXN];
int q[MAXN];
int n, m;
void addEdge(int u, int v) {
	nxt[cnt] = head[u];
	to[cnt] = v;
	head[u] = cnt++;
}
int main() {
	if (cin >> n >> m) {
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			addEdge(u, v);
			indegree[v]++;
		}
	}
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q[r++] = i;
			lines[i] = 1;
		}
	}
	int ans = 0;
	while (l < r) {
		int u = q[l++];
		if (head[u] == 0) {
			ans = (ans + lines[u]) % MOD;
		}
		else {
			for (int ei = head[u]; ei > 0; ei = nxt[ei]) {
				int v = to[ei];
				lines[v] = (lines[v] + lines[u]) % MOD;
				if (--indegree[v] == 0) {
					q[r++] = v;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}