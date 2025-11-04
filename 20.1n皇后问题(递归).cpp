//#include<iostream>
//#include<cmath>
//using namespace std;
//class Solution {
//public:
//    int totalNQueens(int n) {
//        if (n < 1)return 0;
//        int* path = new int[n];
//        int ans = f1(0, path, n);
//        delete[] path;
//        return ans;
//    }
//    int f1(int i, int path[], int n) {
//        if (i == n) return 1;
//        int ans = 0;
//        for (int j = 0; j < n; j++) {
//            if (check(path, i, j)) {
//                path[i] = j;
//                ans += f1(i + 1, path, n);
//            }
//        }
//        return ans;
//
//    }
//    bool check(int path[], int i, int j) {
//        for (int k = 0; k < i; k++) {
//            if (abs(j - path[k]) == abs(i - k) || j == path[k]) return false;
//        }
//        return true;
//    }
//};
