//#include<iostream>
//#include<vector>
//using namespace std;
//int arr[10001];
//void SwapExclusiveOr() {
//	int a = 3;
//	int b = -10;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	cout << a << " " << b << endl;
//	
//}
//void Swap(int i, int j) {
//	arr[i] = arr[i] ^ arr[j];
//	arr[j] = arr[i] ^ arr[j];
//	arr[i] = arr[i] ^ arr[j];
//}
//// 必须保证 n 是 0 或 1
//// 0 -> 1, 1 -> 0
//int flip(int n) {
//    return n ^ 1;
//}
//
//// 非负数返回 1，负数返回 0
//int sign(int n) {
//    // 右移 31 位得到符号位（算术右移）
//    // 正数 n>>31 = 0, 负数 n>>31 = -1 (二进制全1)
//    // 所以要先逻辑右移（Java 用 >>>，C++ 只有 >>，需要转换）
//    // 这里可以用 unsigned 强制逻辑右移
//    return flip((unsigned int)(n) >> 31);
//}
//
//// 有溢出风险的实现
//int getMax1(int a, int b) {
//    int c = a - b;
//    // 如果 c >= 0，则 returnA = 1, returnB = 0
//    // 如果 c < 0，则 returnA = 0, returnB = 1
//    int returnA = sign(c);
//    int returnB = flip(returnA);
//    return a * returnA + b * returnB;
//}
//
//// 没有溢出风险的安全实现
//int getMax2(int a, int b) {
//    int c = a - b;
//
//    int sa = sign(a); // a 的符号（a>=0 为1，否则0）
//    int sb = sign(b); // b 的符号
//    int sc = sign(c); // c 的符号
//
//    // 判断 a 和 b 的符号是否不同
//    int diffAB = sa ^ sb;     // 不同为1，相同为0
//    int sameAB = flip(diffAB); // 相同为1，不同为0
//
//    // 如果 a、b 符号不同，用 sa 决定
//    // 如果符号相同，用 sc 决定
//    int returnA = diffAB * sa + sameAB * sc;
//    int returnB = flip(returnA);
//
//    return a * returnA + b * returnB;
//}
//int missingNumber(const vector<int>& nums) {
//    int eorAll = 0, eorHas = 0;
//    for (int i = 0; i < nums.size(); i++) {
//        eorAll ^= i;        // 异或所有下标
//        eorHas ^= nums[i];  // 异或数组中的数
//    }
//    eorAll ^= nums.size();   // 再异或上最后一个数字 n
//    return eorAll ^ eorHas;  // 两部分异或后得到缺失的数字
//}
//// 数组中只有一种数出现了奇数次，其他数都出现了偶数次
//// 返回出现了奇数次的那个数
//int singleNumber(vector<int>& nums) {
//    int eor = 0; // eor 表示异或结果
//    for (int num : nums) {
//        eor ^= num; // 异或运算：相同为0，不同为1
//    }
//    return eor;
//}
//
//// 数组中有两种数出现了奇数次，其他数都出现了偶数次
//// 返回这两个出现奇数次的数
//vector<int> singleNumber2(vector<int>& nums) {
//    int eor1 = 0;
//    for (int num : nums) {
//        eor1 ^= num;  // eor1 = a ^ b
//    }
//
//    // 提取出 a 和 b 二进制中最右侧不同的一位
//    int rightOne = eor1 & (-eor1);
//
//    int eor2 = 0;
//    for (int num : nums) {
//        if ((num & rightOne) == 0) {  // 根据该位是否为 0 分组
//            eor2 ^= num;
//        }
//    }
//
//    // eor2 是一个奇数次的数，另一个是 eor1 ^ eor2
//    vector<int> ans;
//    ans.push_back(eor2);
//    ans.push_back(eor1 ^ eor2);
//    return ans;
//}
//
//// 通用方法：数组中只有 1 种数出现次数少于 m 次，其他数都出现了 m 次
//int find(const vector<int>& arr, int m) {
//    // cnts[i] 表示第 i 位上有多少个 1
//    int cnts[32] = { 0 };
//
//    // 统计每一位上 1 的总次数
//    for (int num : arr) {
//        for (int i = 0; i < 32; i++) {
//            cnts[i] += (num >> i) & 1;
//        }
//    }
//
//    int ans = 0;
//    // 对每一位取模，如果不能被 m 整除，说明这个位上属于“那个出现少的数”
//    for (int i = 0; i < 32; i++) {
//        if (cnts[i] % m != 0) {
//            ans |= (1 << i);
//        }
//    }
//
//    return ans;
//}
//
//// LeetCode 测试：数组中除一个数外其他数都出现了 3 次
//int singleNumber(const vector<int>& nums) {
//    return find(nums, 3);
//}
//int main() {
//	SwapExclusiveOr();
//    int a = 10;
//    int b = 3;
//    // getMax1 可能出错（因为 a - b 溢出）
//    cout << getMax1(a, b) << endl;
//
//    // getMax2 永远正确
//    cout << getMax2(a, b) << endl;
//
//    vector<int> nums = { 3, 0, 1 };
//    cout << missingNumber(nums) << endl;  // 输出 2
//	
//    vector<int> nums = { 2, 3, 2, 3, 4 };
//    cout << singleNumber(nums) << endl; // 输出 4
//    
//    vector<int> nums = { 2, 4, 3, 3, 2, 5 };
//    vector<int> ans = singleNumber2(nums);
//    cout << ans[0] << " " << ans[1] << endl; // 输出：4 5（顺序可能不同）
//    
//    vector<int> nums = { 2, 2, 3, 2 }; // 3 出现 1 次，其它出现 3 次
//    cout << singleNumber(nums) << endl; // 输出 3
//    return 0;
//}