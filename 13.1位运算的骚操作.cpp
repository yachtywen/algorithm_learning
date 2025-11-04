//#include<iostream>
//using namespace std;
////判断某个数是否为2的幂
//bool isPowerOfTwo(int n) {
//	return n > 0 && n == (n & -n);
//}
////判断一个整数是不是3的幂
//bool isPowerOfThree(int n) {
//	// 如果一个数字是3的某次幂，那么这个数一定只含有3这个质数因子
//	// 1162261467是int型范围内，最大的3的幂，它是3的19次方
//	// 这个1162261467只含有3这个质数因子，如果n也是只含有3这个质数因子，那么
//	// 1162261467 % n == 0
//	// 反之如果1162261467 % n != 0 说明n一定含有其他因子
//	return n > 0 && 1162261467 % n == 0;
//}
////找的距离n最近且大于等于n的2的幂
//int near2power(int n) {
//	if (n <= 0) return -1;
//	n--;
//	n |= n >> 1;
//	n |= n >> 2;
//	n |= n >> 4;
//	n |= n >> 8;
//	n |= n >> 16;
//	return n + 1;
//}
////将[left,right]的数字都&运算求值
//int rangeBitwiseAnd(int left,int right) {
//	while (right > left) {
//		//每次减去二进制数中的最右侧的1
//		right -= right & -right;
//	}
//	return right;
//}
////反转二进制数
//int reverseBits(int n) {
//	n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
//	n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
//	n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
//	n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
//	n = (n >> 16) | (n << 16);
//	return n;
//}
////返回二进制数中有几个1
//int cntOnes(int n) {
//	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
//	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
//	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
//	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
//	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
//	return n;
//}
//int main() {
//}