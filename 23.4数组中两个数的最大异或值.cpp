//#include<iostream>
//#include<vector>
//#include<unordered_set>
//using namespace std;
////使用前缀树解决
//class Solution01 {
//public:
//    static const int MAXN = 3000001;
//    int tree[MAXN][2];
//    int cnt ;
//    int high;
//    int findMaximumXOR(vector<int>& nums) {
//        build(nums);
//        int ans = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            ans = max(ans, maxXor(nums[i]));
//        }
//        return ans;
//    }
//    void build(vector<int>& nums) {
//        cnt = 1;
//        int max_value = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            max_value = max(max_value, nums[i]);
//        }
//        while (max_value != 0) {
//            max_value /= 2;
//            high++;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            insert(nums[i]);
//        }
//    }
//    void insert(int num) {
//        int cur = 1;
//        for (int i = high; i >= 0; i--) {
//            int path = (num >> i) & 1;
//            if (tree[cur][path] == 0) {
//                tree[cur][path] = ++cnt;
//            }
//            cur = tree[cur][path];
//        }
//    }
//    int maxXor(int num) {
//        int ans = 0;
//        int cur = 1;
//        for (int i = high; i >= 0; i--) {
//            int status = (num >> i) & 1;
//            int want = status ^ 1;
//            if (tree[cur][want] == 0) {
//                want ^= 1;
//            }
//            ans |= (status ^ want) << i;
//            cur = tree[cur][want];
//        }
//        return ans;
//    }
//};
//class Solution02 {
//public:
//    int findMaximumXOR(vector<int>& nums) {
//        int maxVal = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (maxVal < nums[i]) maxVal = nums[i];
//        }
//        int high = 0;
//        while (maxVal) {
//            maxVal /= 2;
//            high++;
//        }
//        unordered_set<int> vals;
//        int ans = 0;
//        for (int i = high; i >= 0; i--) {
//            vals.clear();
//            int better = ans | (1 << i);
//            for (int j = 0; j < nums.size(); j++) {
//                int tmp = (nums[j] >> i) << i;
//                vals.insert(tmp);
//                if (vals.count(better ^ tmp)) {
//                    ans = better;
//                    break;
//                }
//                
//            }
//        }
//        return ans;
//    }
//};