#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(int i,int e,long long s,long long limit,vector<long long>& ans,vector<int>& arr) {
	if (s > limit)return;
	if (i == e) {
		ans.push_back(s);
		return;
	}
		dfs(i + 1, e, s, limit, ans, arr);
		dfs(i + 1, e, s + arr[i], limit, ans, arr);
}
int main() {
	int N;
	long long M;
	cin >> N >> M;
	vector<int>arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vector<long long>Lans;
	vector<long long>Rans;
	int mid = N / 2;
	long long ans=0;
	dfs(0, mid, 0, M, Lans, arr);
	dfs(mid, N, 0, M, Rans, arr);
	sort(Lans.begin(), Lans.end());
	sort(Rans.begin(), Rans.end());
	for (int i = Lans.size() - 1, j = 0; i >= 0; i--) {
		while (j < Rans.size() && Rans[j] + Lans[i] <= M) {
			j++;
		}ans += j;
	}
	cout << ans;
	return 0;
}