//#include"iostream"
//#include"vector"
//#include"string"
/*原理:
1)思考一个问题在大范围上的答案，是否等于，左部分的答案 + 右部分的答案 + 跨越左右产生的答案
2)计算“跨越左右产生的答案”时，如果加上左、右各自有序这个设定，会不会获得计算的便利性
3)如果以上两点都成立，那么该问题很可能被归并分治解决(话不说满，因为总有很毒的出题人)
4)求解答案的过程中只需要加入归并排序的过程即可，因为要让左、右各自有序，来获得计算的便利性*/
//using namespace std;
//const int MAXN = 100001;
//int arr[MAXN];
//int help[MAXN];
//int n;
////运用递归来进行计算
//long smallSum(int l, int r) {
//	if (l == r) return 0;
//	int m = (l + r) / 2;
//	return smallSum(l, m) + smallSum(m + 1, r) + merge(l, m, r);
//
//}
//long merge(int l, int m, int r) {
//	long ans = 0;
//	int sum = 0;
//	int i = l;
//	//计算左半边相对于右边每个数的小和
//	for (int j = m + 1; j <= r; j++) {
//		while (i <= m&&arr[i]<=arr[j]) {
//			sum +=arr[i];
//			i++;
//		}
//		ans += sum;
//	}
//	//计算完小和后将左半边有序+右半边有序的数列变更为一个整体有序的数列
//	i = l;
//	int a = l;
//	int b = m + 1;
//	while (a <= m && b <= r) {
//		help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
//	}
//	while (a <= m) {
//		help[i++] = arr[a++];
//	}
//	while (b <= r) {
//		help[i++] = arr[b++];
//	}
//	for (i = l; i <= r; i++) {
//		arr[i] = help[i];
//	}
//	return ans;
//}
//int main() {
//	string line;
//	while (cin>>n) {
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//		cout << smallSum(0, n - 1) << endl;
//	}
//	return 0;
//}