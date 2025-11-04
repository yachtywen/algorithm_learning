//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cmath>
//using namespace std;
//class Solution {
//public:
//	int halveArray(vector<int>& nums) {
//		priority_queue<double, vector<int>> heap;
//		double sum = 0;
//		for (int i = 0; i < nums.size(); i++) {
//			heap.push((double)nums[i]);
//			sum += nums[i];
//		}
//		sum /= 2;
//		int ans = 0;
//		double minus = 0;
//		while (minus < sum) {
//			double cur = heap.top() / 2;
//			heap.pop();
//			minus += cur;
//			heap.push(cur);
//			ans++;
//		}
//		return ans;
//	}
//};