#include<iostream>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int move[] = { -1,0,1,0,-1 };
        vector<vector<int>>distance(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>>dq;
        distance[0][0] = 0;
        dq.push_front({ 0,0 });
        while (!dq.empty()) {
            pair<int, int>cur = dq.front();
            dq.pop_front();
            int x = cur.first;
            int y = cur.second;
            if (x == m - 1 && y == n - 1)return distance[x][y];
            for (int i = 0; i < 4; i++) {
                int nx = x + move[i];
                int ny = y + move[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int weight = grid[nx][ny];
                    //ºËÐÄÂß¼­
                    if (distance[x][y] + weight < distance[nx][ny]) {
                        distance[nx][ny] = distance[x][y] + weight;
                        if (weight == 0) {
                            dq.push_front({ nx,ny });
                        }
                        else {
                            dq.push_back({ nx,ny });
                        }
                    }
                }
            }
        }
        return -1;
    }
};