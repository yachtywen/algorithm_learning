#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 10010;
class Solution {
public:
	struct Edge {
		int u, v, w;
	};
	int father[MAXN];
	void build(int n){
		for (int i = 0; i <= n; i++) {
			father[i] = i;
		}
	}
	int find(int i) {
		if (i != father[i]) {
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
	int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
		build(n);
		vector<Edge>edges;
		for (int i = 0; i < n; i++) {
			edges.push_back({ 0, i+1, wells[i] });
		}
		for (int i = 0; i < pipes.size(); i++) {
			edges.push_back({ pipes[i][0],pipes[i][1] ,pipes[i][2]});
		}
		sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
			return a.w < b.w;
			});
		int ans = 0;
		for (int i = 0; i < edges.size(); i++) {
			if (unite(edges[i].u, edges[i].v)) {
				ans += edges[i].w;
			}
		}
		return ans;
	}
};