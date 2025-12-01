#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
// Ê±¼ä¸´ÔÓ¶ÈO(n + m) + O(m * log m)
int n, m;
int main() {
	cin >> n >> m;
	vector<vector<pair<int,int>>>graph(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		pair<int, int>tmp1(w, v);
		pair<int, int>tmp2(w, u);
		graph[u].push_back(tmp1);
		graph[v].push_back(tmp2);
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>heap_min;
	for (int i = 0; i < graph[1].size(); i++) {
		heap_min.push(graph[1][i]);
	}
	vector<int>visited(n+1,false);
	visited[1] = true;
	int nodeCnt = 1;
	int ans = 0;
	while (!heap_min.empty()) {
		pair<int, int>cur = heap_min.top();
		heap_min.pop();
		int cost = cur.first;
		int next = cur.second;
		if (!visited[next]) {
			visited[next] = true;
			ans += cost;
			nodeCnt++;
			for (int i = 0; i < graph[next].size(); i++) {
				heap_min.push(graph[next][i]);
			}
		}
		
	}
	if (nodeCnt == n) {
		cout << ans << endl;
	}
	else {
		cout << "orz" << endl;
	}
	return 0;
}