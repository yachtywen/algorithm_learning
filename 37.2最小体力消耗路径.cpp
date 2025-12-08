#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>dist(r * c, INT_MAX);
        dist[0] = 0;
        pq.push({ 0,0 });
        int move[] = { -1,0,1,0,-1 };
        vector<bool>visited(r * c, false);
        while (!pq.empty()) {
            int w = pq.top().first;
            int x = pq.top().second / c;
            int y = pq.top().second % c;
            pq.pop();
            if (visited[x * c + y])continue;
            if (x == r - 1 && y == c - 1)return dist[(r - 1) * c + c - 1];
            for (int i = 0; i < 4; i++) {
                int nx = x + move[i];
                int ny = y + move[i + 1];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                    int d = abs(heights[x][y] - heights[nx][ny]);
                    if (max(d,dist[x * c + y]) < dist[nx * c + ny]) {
                        dist[nx * c + ny] = max(d, dist[x * c + y]);
                        pq.push({ dist[nx * c + ny],nx * c + ny});
                        visited[x * c + y] = true;
                    }
                }
            }
        }
        return -1;
    }
};