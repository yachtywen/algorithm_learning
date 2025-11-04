//#include"iostream"
//#include"vector"
//#include"algorithm"
//using namespace std;
//const int MAXN = 100001;
//
//int arr[MAXN];
//int help[MAXN];
//int n;
////merge函数将两部分有序的数列合并为一个大的有序数列
//void merge(int l, int m, int r) {
//	int i = l;
//	int a = l;
//	int b = m + 1;
//	while (a <= m && b <= r) {
//		help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
//	}
//	while (a <= m) {
//		help[i++] = arr[a++];
//	}
//	while (b <= m) {
//		help[i++] = arr[b++];
//	}
//	for (int i = l; i <= r; i++) {
//		arr[i] = help[i];
//	}
//}
////递归的归并排序
//void mergeSort01(int l, int r) {
//	if (l == r) {
//		return;
//	}
//	int m = (l + r) / 2;
//	mergeSort01(l, m);
//	mergeSort01(m + 1, r);
//	merge(l, m, r);
//}
////非递归的归并排序
//void mergeSort02() {
//	for (int step = 1; step < n; step * 2) {
//		int l = 0;
//		while (l < n) {
//			int m = l + step - 1;
//			if (m + 1 >= n) {
//				break;
//			}
//			int r = min(l + step * 2 - 1, n - 1);
//			merge(l, m, r);
//			l = r + 1;
//		}
//	}
//}
//
//int main() {
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//
//    // mergeSort01(0, n - 1);
//    mergeSort02();
//
//    for (int i = 0; i < n - 1; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << arr[n - 1] << endl;
//
//    return 0;
//}