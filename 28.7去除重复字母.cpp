#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
         vector<int>cnt(26,0);
         vector<bool>is_in(26,false);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }
        vector<int>st(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']--;
            //跳过栈中已有元素
            if (is_in[s[i] - 'a'])continue;
            while (r > 0 && s[st[r - 1]] > s[i] && cnt[s[st[r - 1]] - 'a'] > 0) {
                is_in[s[st[r - 1]] - 'a'] = false;
                r--;
            }
            st[r++] = i;
            is_in[s[i] - 'a'] = true;

        }
        string ans;
        for (int i = 0; i < r; i++) {
            ans += s[st[i]];
        }
        return ans;
    }
};
int main() {
    string s;
    cin >> s;
    Solution s1;
    cout << s1.removeDuplicateLetters(s);
    return 0;
}