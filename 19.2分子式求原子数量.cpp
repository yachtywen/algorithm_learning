//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//class Solution {
//public:
//    int where;
//    string countOfAtoms(string formula) {
//        where = 0;
//        string ans;
//        map<string, int> mp = f(formula, 0);
//        for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
//            ans += it->first;
//            if (it->second > 1)ans += to_string(it->second);
//        }
//        return ans;
//    }
//    map<string, int> f(string s, int i) {
//        map<string, int> ans;
//        string name;
//        map<string, int> pre;
//        int cnt = 0;
//        while (i < s.size()&&s[i]!=')') {
//            if (s[i] >= 'A' && s[i] <= 'Z'||s[i]=='(') {
//                fill(ans, name, pre, cnt);
//                name.clear();
//                pre.clear();
//                cnt = 0;
//                if (s[i] >= 'A' && s[i] <= 'Z') {
//                    name += s[i++];
//                }
//                else {
//                    pre=f(s, i + 1);
//                    i = where + 1;
//                }
//            }
//            else if (s[i] >= 'a' && s[i] <= 'z') {
//                name += s[i++];
//            }
//            else if (s[i] >= '0' && s[i] <= '9') {
//                cnt = cnt * 10 + (s[i++] - '0');
//            }
//            else {
//                i++;
//            }
//        }
//        fill(ans, name, pre, cnt);
//        where = i;
//        return ans;
//    }
//    void fill(map<string,int>& ans, string name, map<string,int>& pre, int cnt) {
//        if (!name.empty() || !pre.empty()) {
//            cnt = (cnt == 0 ? 1 : cnt);
//            if (!name.empty()) {
//                ans[name] += cnt;
//            }
//            else {
//                for (map<string, int>::iterator it = pre.begin(); it != pre.end(); it++) {
//                    ans[it->first] += it->second * cnt;
//                }
//            }
//        }
//    }
//};