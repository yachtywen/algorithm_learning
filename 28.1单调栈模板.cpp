#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> findNearestSmaller(vector<int>& nums) {
	int n = nums.size();
	if (n == 0)return {};
	vector<vector<int>> ans(n, vector<int>(2, -1));
	int* st = new int[n];
	int r = 0;
	//遍历阶段
	//总复杂度为 O(N) + O(N) = O(N)(N 次入栈 + 最多 N 次出栈)
	for (int i = 0; i < n; i++) {
		while (r > 0 && nums[st[r - 1]] >= nums[i]) {
			int cur = st[--r];
			ans[cur][0] = (r == 0) ? -1 : st[r - 1];
			ans[cur][1] = i;
		}
		st[r++] = i;
	}
	//清算阶段，将栈中剩下的元素清算
	while (r > 0) {
		int cur = st[--r];
		ans[cur][0] = (r == 0) ? -1 : st[r - 1];
		ans[cur][1] = -1;
	}
	//修正阶段，将重复数字的右侧数修正
	for (int i = n - 2; i >= 0; i--) {
		if (ans[i][1] != -1 && nums[ans[i][1]] == nums[i]) {
			ans[i][1] = ans[ans[i][1]][1];
		}
	}
	return ans;
}