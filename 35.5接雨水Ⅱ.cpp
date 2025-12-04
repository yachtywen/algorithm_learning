#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty())return 0;
        int n = heightMap.size();
        int m = heightMap[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    pq.push({ heightMap[i][j],i,j });
                    visited[i][j] = true;
                }
            }
        }
        int ans = 0;
        int move[] = { -1,0,1,0,-1 };
        while (!pq.empty()) {
            vector<int>cur = pq.top();
            pq.pop();
            int height = cur[0];
            int x = cur[1];
            int y = cur[2];
            ans += height - heightMap[x][y];
            for (int i = 0; i < 4; i++) {
                int nx = x + move[i];
                int ny = y + move[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    pq.push({ max(height,heightMap[nx][ny]),nx,ny });
                    visited[nx][ny] = true;
                }
            }
        }
        return ans;
    }
};