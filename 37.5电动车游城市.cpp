#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {
        int n = charge.size();
        vector<vector<pair<int, int>>>graph(n);
        for (const vector<int>& path : paths) {
            graph[path[0]].push_back({ path[2],path[1]});
            graph[path[1]].push_back({ path[2],path[0] });
        } 
        
        vector<vector<int>>distance(n, vector<int>(cnt + 1, INT_MAX));
        distance[start][0] = 0;
        vector<vector<bool>>visited(n, vector<bool>(cnt + 1, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({ 0,start,0 });
        while (!pq.empty()) {
            int cost = pq.top()[0];
            int cur = pq.top()[1];
            int power = pq.top()[2];
            pq.pop();
            if (visited[cur][power])continue;
            if (cur == end)return cost;
            visited[cur][power] = true;
            if (power < cnt) {
                int nextPower = power + 1;
                int nextCost = cost + charge[cur];
                if (!visited[cur][nextPower] && nextCost < distance[cur][nextPower]) {
                    distance[cur][nextPower] = nextCost;
                    pq.push({ nextCost,cur,nextPower });
                }
            }
            for (const pair<int,int>edge : graph[cur]) {
                int nextCity = edge.second;
                int  dist = edge.first;
                int restPower = power - dist;
                int nextCost = cost + dist;
                if (restPower >= 0 && !visited[nextCity][restPower] && nextCost < distance[nextCity][restPower]) {
                    distance[nextCity][restPower] = nextCost;
                    pq.push({ nextCost,nextCity,restPower });
                }

            }
        }
        return -1;
    }
};