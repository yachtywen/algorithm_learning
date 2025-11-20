#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
static const int MAXN=100005;
int maxDeque[MAXN];
int minDeque[MAXN];
struct node {
	int x;
	int y;
	node() : x(0), y(0) {}
	node(int x,int y):x(x),y(y){}
};
int main() {
	int N, D;
	cin >> N >> D;
	vector<node> nums(N);
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		node cur(x, y);
		nums[i] = cur;
	}
	sort(nums.begin(), nums.end(), [](const node& a, const node& b) {
		return a.x < b.x;
		});
	int maxh, maxt, minh, mint;
	maxh = maxt = minh = mint = 0;
	int ans = INT_MAX;
	for (int l = 0, r = 0; r < N; r++) {
		while (maxh < maxt && nums[maxDeque[maxt - 1]].y <= nums[r].y) {
			maxt--;
		}
		maxDeque[maxt++] = r;
		while (minh < mint && nums[minDeque[mint - 1]].y >= nums[r].y) {
			mint--;
		}
		minDeque[mint++] = r;
		while (nums[maxDeque[maxh]].y - nums[minDeque[minh]].y >= D) {
			ans = min(ans, nums[r].x - nums[l].x);
			if (l == maxDeque[maxh])maxh++;
			if (l == minDeque[minh])minh++;
			l++;
		}
	}
	cout << ((ans == INT_MAX) ? -1 : ans )<< endl;
	return 0;
}