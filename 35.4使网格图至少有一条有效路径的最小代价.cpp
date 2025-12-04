#include<iostream>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>cost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>>dq;
        cost[0][0] = 0;
        dq.push_back({ 0,0 });
        int dire[] = { -1,0,1,0,-1 };
        while (!dq.empty()) {
            pair<int, int>cur;
            cur = dq.front();
            dq.pop_front();
            int x = cur.first;
            int y = cur.second;
            if (x == m - 1 && y == n - 1)return cost[x][y];
            int di = grid[x][y];
            for (int i = 0; i < 4; i++) {
                int nx = x + dire[i];
                int ny = y + dire[i + 1];
                int weight = 0;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if ((di == 1 && i != 1)|| (di == 2 && i != 3)|| 
                         (di == 3 && i != 2)|| (di == 4 && i != 0)){
                        weight = 1;
                    }
                    if (cost[x][y] + weight < cost[nx][ny]) {
                        cost[nx][ny]=cost[x][y] + weight;
                        if (weight == 1)dq.push_back({ nx,ny });
                        else dq.push_front({ nx,ny });
                    }
                    
                }
            }
           
        }
        return -1;
    }
};