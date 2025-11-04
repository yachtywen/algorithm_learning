//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//    int where;
//    string decodeString(string s) {
//        where = 0;
//        return f(s, 0);
//    }
//    string f(string s, int i) {
//        string path;
//        string times;
//        int cnt;
//        while (i < s.size()) {
//            if (s[i] >= 'a' && s[i] <= 'z') {
//                path.push_back(s[i]);
//            }
//            else if(s[i]>='0'&&s[i]<='9') {
//                times.push_back(s[i]);
//            }
//            else if (s[i] == '[') {
//                cnt = stoi(times);
//                times.clear();
//                string son=f(s, i + 1);
//                while (cnt--) {
//                    path += son;
//                }
//                i = where;
//            }
//            else {
//                where = i;
//                return path;
//            }
//            i++;
//        }
//        return path;
//    }
//
//};