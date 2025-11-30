#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size();
        int n = target.size();
        vector<int>indegree(n - m + 1, m);
        vector<vector<int>>graph(n);
        vector<int>queue(n - m + 1);
        int l = 0, r = 0;
        for (int i = 0; i < n - m + 1; i++) {
            for (int j = 0; j < m; j++) {
                if (target[i + j] == stamp[j]) {
                    if (--indegree[i] == 0)queue[r++] = i;
                }
                else {
                    graph[i + j].push_back(i);
                }
            }
        }
        vector<bool>visited(n, false);
        vector<int> path;
        while (l < r) {
            int cur = queue[l++];
            path.push_back(cur);
            for (int i = 0; i < m; i++) {
                int pos = cur + i;
                if (!visited[pos]) {
                    visited[pos] = true;
                    for (int j = 0; j < graph[pos].size(); j++) {
                        if (--indegree[graph[pos][j]] == 0)queue[r++] = graph[pos][j];
                    }
                }
            }
        }
        if (path.size() != n - m + 1)return {};
        reverse(path.begin(), path.end());
        return path;
    }
};