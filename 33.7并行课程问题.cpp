#include<iostream>
#include<vector>
using namespace std; 
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>graph(time.size());
        vector<int>queue(time.size());
        vector<int>indegree(time.size(),0);
        vector<int>dist(time.size(), 0);
        for (int i = 0; i < relations.size(); i++) {
            int u = relations[i][0]-1;
            int v = relations[i][1]-1;
            graph[u].push_back(v);
            indegree[v]++;
        }
        int l = 0, r = 0;
        for (int i = 0; i < time.size(); i++) {
            if (indegree[i] == 0) {
                queue[r++] = i;
            }
            dist[i] = time[i];
        }
        int ans = 0;
        while (l < r) {
                int cur = queue[l++];
                ans = max(ans, dist[cur]);
                for (int next : graph[cur]) {
                    dist[next] = max(dist[next], dist[cur] + time[next]);
                    if (--indegree[next] == 0) {
                        queue[r++] = next;
                    }
                }
        }
        return ans;
    }
};