#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>>graph;
    unordered_set<string>visited;
    vector<string>q;
    int minStickers(vector<string>& stickers, string target) {
        graph.resize(26);
        for (int i = 0; i < stickers.size(); i++) {
            string cur = stickers[i];
            sort(cur.begin(), cur.end());
            for (int j = 0; j < cur.length(); j++) {
                if (j == 0 || cur[j] != cur[j - 1]) {
                    graph[cur[j] - 'a'].push_back(cur);
                }
            }
        }
        sort(target.begin(), target.end());
        visited.insert(target);
        q.push_back(target);
        int l = 0;
        int level = 1;
        while (l < q.size()) {
            int size = q.size() - l;
            for (int k = 0; k < size; k++) {
                string cur = q[l++];
                if (cur.empty())continue;
                int firstCharIndex = cur[0] - 'a';
                for (int i = 0; i < graph[firstCharIndex].size(); i++) {
                    string s = graph[firstCharIndex][i];
                    string nextStr = getNext(cur, s);
                    if (nextStr == "") {
                        return level;
                    }
                    else if(visited.find(nextStr)==visited.end()) {
                        visited.insert(nextStr);
                        q.push_back(nextStr);
                    }
                }
            }
            level++;
        }
        return -1;
    }
    string getNext(string& t, string& s) {
        string res = "";
        int i = 0, j = 0;
        while (i < t.length()) {
            if (j == s.length()) {
                res += t[i++];
            }
            else {
                if (t[i] < s[j]) {
                    res += t[i++];
                }
                else if(t[i]>s[j]) {
                    j++;
                }
                else {
                    i++;
                    j++;
                }
            }
        }
        return res;
    }
};