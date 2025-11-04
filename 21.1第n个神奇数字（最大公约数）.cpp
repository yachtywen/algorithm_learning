//#include<iostream>
//using namespace std;
////最大公约数
////gcd(a,b){return b==0? a : gcd(b,a%b)}
//class Solution {
//public:
//    int nthMagicalNumber(int n, int a, int b) {
//        long long lcmVal = lcm(a, b);
//        long long ans = 0;
//        long long l = 0, r = (long long)n * min(a, b), m;
//        while (l <= r) {
//            m = (l + r) / 2;
//            if (m / a + m / b - m / lcmVal >= n) {
//                ans = m;
//                r = m-1;
//            }
//            else {
//                l = m+1;
//            }
//        }
//        return (int)(ans % 1000000007);
//    }
//    int gcd(int a, int b) {
//        return b == 0 ? a : gcd(b, a % b);
//    }
//    int lcm(int a, int b) {
//        return a / gcd(a, b) * b;
//    }
//};