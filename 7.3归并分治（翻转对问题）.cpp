//#include"iostream"
//using namespace std;
//const int MAXN = 100001;
//long arr[MAXN];
//long help[MAXN];
//int n;
//long mergeFlip(int l,int r){
//    if (l == r) return 0;
//    int m = (l + r) / 2;
//    return mergeFlip(l, m) + mergeFlip(m + 1, r) + merge(l, m, r);
//}
//long merge(int l,int m,int r){
//    int ans = 0;
//    int j = m+1;
//    for (int i = l; i <= m; i++) {
//        while (arr[i] > arr[j] * 2&&j<=r) {
//            ans += j - m;
//            j++;
//        }
//    }
//    int a = l;
//    int b = m + 1;
//    int i = l;
//    while (a <= m && b <= r) {
//        help[i++] = arr[a] < arr[b] ? arr[a++] : arr[b++];
//    }
//    while (a <= m) {
//        help[i++] = arr[a++];
//    }
//    while (b <= r) {
//        help[i++] = arr[b++];
//    }
//    for (int i = l; i < r; i++) {
//        arr[i] = help[i];
//    }
//    return ans;
//}
//int main(){
//    while (cin >> arr[n]) {
//        n++;
//    }
//    cout << mergeFlip(0, n-1);
//    return 0;
//}