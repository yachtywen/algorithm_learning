//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//const int MAXN = 100001;
//int line[MAXN][2];
//int n;
////通过堆排序将每个线段通过左节点由小到大排序
//void heapify(int i, int size) {
//    int l = i * 2 + 1;
//    while (l < size) {
//        int best = l + 1 < size && line[l + 1][0] > line[l][0] ? l + 1 : l;
//        best = line[best][0] > line[i][0] ? best : i;
//        if (best == i) {
//            break;
//        }
//        swap(line[best], line[i]);
//        i = best;
//        l = i * 2 + 1;
//    }
//}
//void heapSort() {
//    // 建堆（大根堆）
//    for (int i = n / 2 - 1; i >= 0; i--) {
//        heapify(i, n);
//    }
//    // 排序
//    int size = n;
//    while (size > 1) {
//        swap(line[0], line[--size]);
//        heapify(0, size);
//    }
//}
//int compute() {   
//    //排序
//    heapSort();
//    //申请一个小根堆
//    priority_queue<int, vector<int>, greater<int>> heap;
//    int ans = 0;
//    for (int i = 0; i < n; i++) {
//        while (!heap.empty() && heap.top() <= line[i][0]) {
//            heap.pop();
//        }
//        heap.push(line[i][1]);
//        ans = heap.size() > ans ? heap.size() : ans;
//    }
//    return ans;
//}
//int main() {
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//          cin >> line[i][0] >> line[i][1];
//    }
//        cout << compute();
//    
//    return 0;
//}
