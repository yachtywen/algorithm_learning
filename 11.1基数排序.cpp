//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//const int BASE = 10;
//const int MAXN = 50001;
//int help[MAXN];
//int cnts[BASE];
//class RadixSort {
//public:
//	vector<int> sortArray(vector<int>& arr) {
//		int n = arr.size();
//		if (n > 1) {
//			int minVal = arr[0];
//			//找到数组中最小值
//			for (int i = 1; i < n; i++) {
//				if (arr[i] < minVal) {
//					minVal = arr[i];
//				}
//			}
//			int maxVal = 0;
//			for (int i = 0; i < n; i++) {
//				//确保数组中所有数都为正数
//				arr[i] -= minVal;
//				//找到数组中最大值
//				if (arr[i] > maxVal) {
//					maxVal = arr[i];
//				}
//			}
//			//计算数组的最多位数
//			int b = bits(maxVal);
//			//基数排序
//			radixSort(arr, n, b);
//			//还原数组
//			for (int i = 0; i < n; i++) {
//				arr[i] += minVal;
//			}
//		}
//		return arr;
//	}
//private:
//	//计算位数
//	int bits(int number) {
//		int ans = 0;
//		while (number > 0) {
//			ans++;
//			number /= BASE;
//		}
//		return ans;
//	}
//	//基数排序
//	void radixSort(vector<int>& arr, int n, int bits) {
//		for (int offset = 1; bits > 0; offset *= BASE, bits--) {
//			for (int i = 0; i < 10; i++) {
//				cnts[i] = 0;
//			}
//			//计算各尾数共有个数
//			for (int i = 0; i < n; i++) {
//				int digit = (arr[i] / offset) % BASE;
//				cnts[digit]++;
//			}
//			//计算各尾数前共有个数
//			for (int i = 1; i < BASE; i++) {
//				cnts[i] = cnts[i] + cnts[i - 1]; 
//			}
//			//有序放置（从右往左）
//			for (int i = n - 1; i >= 0; i--) {
//				int digit= (arr[i] / offset) % BASE;
//				help[--cnts[digit]] = arr[i];
//			}
//			//放回arr数组
//			for (int i = 0; i < n; i++) {
//				arr[i] = help[i];
//			}
//		}
//	}
//};