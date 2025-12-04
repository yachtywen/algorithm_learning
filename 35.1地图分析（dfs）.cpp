#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static const int MAXN = 101;
    int q[MAXN * MAXN][2];
    int l, r;
    bool visited[MAXN][MAXN];
    int maxDistance(vector<vector<int>>& grid) {
        l = r = 0;
        int n = grid.size();
        int seas = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q[r][0] = i;
                    q[r++][1] = j;
                    visited[i][j] = true;
                }
                else {
                    seas++;
                    visited[i][j] = false;
                }
            }
        }
        if (seas == 0 || seas == n * n)return -1;
        int level = 0;
        int dict[] = { -1,0,1,0,-1 };
        while (l < r) {
            level++;
            int size = r - l;
            for (int i = 0; i < size; i++) {
                int x = q[l][0];
                int y = q[l++][1];
                for (int j = 0; j < 4; j++) {
                    int nx = x+dict[j];
                    int ny = y+dict[j+1];
                    if (nx>=0&&ny>=0&&nx<n&&ny<n&&!visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q[r][0] = nx;
                        q[r++][1] = ny;
                    }
                }
            }
        }
        return level - 1;
    }
};