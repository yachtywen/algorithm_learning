#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    static const int MAXN = 31;
    static const int MAXM = 31;
    static const int MAXK = 6;
    int move[5] = { -1,0,1,0,-1 };
    bool visited[MAXN][MAXM][1 << MAXK];
    int q[MAXN * MAXM * (1 << MAXK)][3];
    int l, r, n, m, totalKeys;
    void build(vector<string>& grid) {
        l = r = totalKeys = 0;
        n = grid.size();
        m = grid[0].length();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c = grid[i][j];
                if (c == '@') {
                    q[r][0] = i;
                    q[r][1] = j;
                    q[r++][2] = 0;
                    visited[i][j][0] = true;
                }
                if (c >= 'a' && c <= 'f')totalKeys |= (1 << (c - 'a'));
            }
        }
    }
    int shortestPathAllKeys(vector<string>& grid) {
        build(grid);
        int level = 1;
        while (l < r) {
            int size = r - l;
            for (int k = 0; k < size; k++) {
                int x = q[l][0];
                int y = q[l][1];
                int s = q[l++][2];
                for (int i = 0; i < 4; i++) {
                    int nx = x + move[i];
                    int ny = y + move[i + 1];
                    int ns = s;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#')continue;
                    char c = grid[nx][ny];
                    if (c >= 'A' && c <= 'F' && ((ns & (1 << (c - 'A'))) == 0)){
                        continue;
                    }
                    if (c >= 'a' && c <= 'f') {
                        ns |= 1 << (c - 'a');
                    }
                    if (ns == totalKeys)return level;
                    if (!visited[nx][ny][ns]) {
                        visited[nx][ny][ns] = true;
                        q[r][0] = nx;
                        q[r][1] = ny;
                        q[r++][2] = ns;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};