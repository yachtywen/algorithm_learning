#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int>dist(r * c, INT_MAX);
        vector<bool>visited(r * c, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        int move[] = { -1,0,1,0,-1 };
        pq.push({ grid[0][0],0});
        dist[0] = grid[0][0];
        while (!pq.empty()) {
            int w = pq.top().first;
            int x = pq.top().second / c;
            int y = pq.top().second % c;
            pq.pop();
            if (x == r - 1 && y == c - 1)return dist[x * c + y];
            if (visited[x * c + y])continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + move[i];
                int ny = y + move[i + 1];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c&&!visited[nx*c+ny]) {
                    if (max(dist[x * c + y], grid[nx][ny]) < dist[nx * c + ny]) {
                        dist[nx * c + ny] = max(dist[x * c + y], grid[nx][ny]);
                        pq.push({ dist[nx * c + ny],nx * c + ny });
                    }
                }
            }
            visited[x * c + y] = true;
        }
        return -1;
    }
};