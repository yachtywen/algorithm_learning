#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int>indegree(quiet.size());
        vector<int>queue(quiet.size());
        vector<vector<int>>graph(quiet.size());
        for (int i = 0; i < richer.size(); i++) {
            int u = richer[i][0];
            int v = richer[i][1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        int l = 0, r = 0;
        for (int i = 0; i < quiet.size(); i++) {
            if (indegree[i] == 0)queue[r++]=i;
        }
        vector<int>ans(quiet.size());
        for (int i = 0; i < quiet.size(); i++) {
            ans[i] = i;
        }
        while (l < r) {
            int cur = queue[l++];
            for (int i = 0; i < graph[cur].size(); i++) {
                if (quiet[ans[cur]] < quiet[ans[graph[cur][i]]]) {
                    ans[graph[cur][i]]=ans[cur];
                }
                if (--indegree[graph[cur][i]] == 0)queue[r++] = graph[cur][i];
            }
        }
        return ans;
    }
};