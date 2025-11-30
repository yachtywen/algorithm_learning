#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<int>indegree(26, -1);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                indegree[words[i][j] - 'a'] = 0;
            }
        }
        vector<vector<int>>graph(26);
        for (int i = 0; i < words.size() - 1; i++) {
            string cur = words[i];
            string next = words[i + 1];
            int p = 0;
            while (p < cur.size() && p < next.size()) {
                if (cur[p] != next[p]) {
                    graph[cur[p] - 'a'].push_back(next[p] - 'a');
                    indegree[next[p] - 'a']++;
                    break;
                }
                p++;
            }
            if (p < cur.length() && p == next.length()) {
                return "";
            }
        }
        vector<int>queue(26);
        int l = 0, r = 0;
        int kinds = 0;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] != -1)kinds++;
            if (indegree[i] == 0)queue[r++] = i;
        }
        string ans = "";
        while (l < r) {
            int cur = queue[l++];
            ans += (char)(cur + 'a');
            for (int i = 0; i < graph[cur].size(); i++) {
                if (--indegree[graph[cur][i]] == 0)queue[r++] = graph[cur][i];
            }
        }
        return ans.length() == kinds ? ans : "";

    }
};