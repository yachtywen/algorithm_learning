//#include<iostream>
//#include<vector>
//#include<stack>
//#include<string>
//using namespace std;
//class Solution {
//public:
//    string decodeString(string s) {
//        stack<int> times;
//        stack<string> ch;
//        for (int i = 0; i < s.size(); i++) {
//            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
//                string cur;
//                while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
//                    cur += s[i];
//                    i++;
//                }
//                ch.push(cur);
//                i -= 1;
//                continue;
//            }
//            else if(s[i]>='0'&&s[i]<='9') {
//                string cur;
//                while (s[i] >= '0' && s[i] <= '9') {
//                    cur += s[i];
//                    i++;
//                }
//                int num = stoi(cur);
//                times.push(num);
//                i -= 1;
//                continue;
//            }
//            else if (s[i] == '[') {
//                ch.push("[");
//            }
//            else if(s[i] == ']') {
//                string temp;
//                while (ch.top() != "[") {
//                    temp = ch.top() + temp;
//                    ch.pop();
//                }
//                int t = times.top();
//                times.pop();
//                ch.pop();
//                string cur;
//                for (int i = 0; i < t; i++) {
//                   cur += temp;
//                }
//                ch.push(cur);
//                
//            }
//        }
//        stack<string> rch;
//        while (!ch.empty()) {
//            rch.push(ch.top());
//            ch.pop();
//        }
//        string ans;
//        while (!rch.empty()) {
//            ans += rch.top();
//            rch.pop();
//        }
//        return ans;
//    }
//};
//int main() {
//    string s;
//    cin >> s;
//    Solution solution;
//    cout << solution.decodeString(s)<< endl;
//    return 0;
//}
