#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            graph[u].push_back({ v,w });
        }
        vector<bool>visited(n + 1, false);
        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n + 1, INT_MAX);
        pq.push({ 0,k });
        dist[k] = 0;
        while (!pq.empty()) {
            pair<int, int>cur = pq.top();
            pq.pop();
            int p = cur.second;
            if (visited[p])continue;
            visited[p] = true;
            for (int i = 0; i < graph[p].size(); i++) {
                int v = graph[p][i].first;
                int w = graph[p][i].second;
                if (!visited[v] && w + dist[p] < dist[v]) {
                    dist[v] = w + dist[p];
                    pq.push({ dist[v],v });
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};