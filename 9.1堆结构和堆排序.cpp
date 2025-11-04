//#include<iostream>
//#include<vector>
//using namespace std;
//const int MAXN = 100001;
//vector<int> arr(MAXN);
//int n;
////向上调整大根堆
////时间复杂度o(nlogn)
//void heapInsert(int i) {
//	while (arr[i] > arr[(i - 1) / 2]) {
//		swap(arr[i], arr[(i - 1) / 2]);
//		i = (i - 1) / 2;
//	}
//}
////从i位置开始向下调整大根堆
////时间复杂度o(n)
//void heapify(int i, int size) {
//	int l = i * 2 + 1;
//	while (l < size) {
//		int best = l + 1 < size && arr[l + 1] > arr[l] ? l + 1 : l;
//		best = arr[best] > arr[i] ? best : i;
//		if (best == i) {
//			break;
//		}
//		swap(arr[best], arr[i]);
//		i = best;
//		l = i * 2 + 1;
//	}
//}
////以下两种堆排序的时间复杂度及空间复杂度均为o(nlogn)
////运用向上调整大根堆的操作来进行堆排序
//void heapSort1() {
//	for (int i = 0; i < n; i++) {
//		heapInsert(i);
//	}
//	int size = n;
//	while (size > 1) {
//		swap(arr[0], arr[--size]);
//		heapInsert(size-1);
//	}
//}
////运用向下调整大根堆的操作来进行堆排序
//void heapSort2() {
//	for (int i = n - 1; i >= 0; i--) {
//		heapify(i, n);
//	}
//	int size = n;
//	while (size > 1) {
//		swap(arr[0], arr[--size]);
//		heapify(0, size);
//	}
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	//heapSort1();
//	heapSort2();
//	for (int i = 0; i < n - 1; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << arr[n - 1] << endl;
//
//	return 0;
//}