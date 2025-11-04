//#include"iostream"
//#include"cstdlib"
//#include"ctime"
//using namespace std;
//const int MAXN = 100001;
//int arr[MAXN];
//int n;
//void swapArr(int i, int j) {
//	int tmp = arr[i];
//	arr[i] = arr[j];
//	arr[j] = tmp;
//}
////快速排序经典写法（不推荐）
//void quickSort1(int l, int r) {
//	if (l >= r) {
//		return;
//	}
//	int x = arr[l + rand() % (r - l + 1)];
//	int mid = 0;
//	int a = l, xi = 0;
//	for (int i = l; i <= r; i++) {
//		if (arr[i] <= x) {
//			if (arr[i] == x) xi = a;
//			swapArr(a, i);
//			a++;
//		}
//	}
//	swapArr(xi, a - 1);
//	mid = a - 1;
//	quickSort1(l, mid-1);
//	quickSort1(mid + 1, r);
//}
////荷兰国旗三路划分
//void quickSort2(int l, int r) {
//		if (l >= r) {
//		return;
//	}
//	//生成随机数（范围在l---r之间）
//	int x = arr[l + rand() % (r - l + 1)];
//	int first = l;
//	int last = r;
//	int i = l;
//	// 已知arr[l....r]范围上一定有x这个值
//	// 划分数组 <x放左边，==x放中间，>x放右边
//	// 把全局变量first, last，更新成==x区域的左右边界
//	while (i <= last) {
//		if (arr[i] < x) {
//			swapArr(first++, i++);
//		}
//		else if (arr[i] > x) {
//			swapArr(i, last--);
//		}
//		else {
//			i++;
//		}
//	}
//	int left = first;
//	int right = last;
//	//递归
//	quickSort2(l, left - 1);
//	quickSort2(right + 1, r);
//}
////好 时间复杂度 o(N*logN)
////差            o(N^2)
////->根据期望算出复杂度 o(N*logN)