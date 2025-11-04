//#include<iostream>
//using namespace std;
//class Solution {
//public:
//    int totalNQueens(int n) {
//        if (n < 1) return 0;
//        int limit = (1 << n) - 1;
//        return f2(limit, 0, 0, 0);
//    }
//    int f2(int limit, int col, int left, int right) {
//        if (col == limit) return 1;
//        int ban = col | left | right;
//        int candidate = limit & (~ban);
//        int ans = 0;
//        while (candidate != 0) {
//            int place = candidate & (-candidate);
//            candidate ^= place;
//            ans += f2(limit, col | place, (left | place) >> 1, (right | place) << 1);
//        }
//        return ans;
//    }
//};
