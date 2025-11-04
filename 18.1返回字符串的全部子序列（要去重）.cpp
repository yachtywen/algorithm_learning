//#include<iostream>
//#include<vector>
//#include<unordered_set>
//#include<string>
//using namespace std;
//class Solution {
//public:
//    vector<string> generatePermutation(string s) {
//        unordered_set<string> set;
//        string path;
//        f1(s, 0, path, set);
//        vector<string> ans(set.begin(), set.end());
//        return ans;
//    }
//    void f1(string& s, int i, string& path, unordered_set<string>& set) {
//        if (i == s.size()) {
//            set.insert(path);
//        }
//        else {
//            path.push_back(s[i]);
//            f1(s, i + 1, path,set);
//            path.pop_back();
//            f1(s, i + 1, path, set);
//        }
//    }
//};
