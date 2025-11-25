#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int>father;
    int sets;
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        father.resize(m * n);
        build(m,n,grid);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    if (i + 1 < m && grid[i + 1][j] == '1') {
                        unite(i * n + j, (i + 1) * n + j);
                    }
                    if (j + 1 < n && grid[i][j + 1] == '1') {
                        unite(i * n + j, i * n + j + 1);
                    }
                }
            }
        }
        return sets;
    }
    void build(int rows,int cols,vector<vector<char>>&grid) {
        sets = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    int idx = i * cols + j;
                    father[idx] = idx;
                    sets++;
                }
            }
        }
    }
    int find(int x) {
        if (father[x] != x)father[x] = find(father[x]);
        return father[x];
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            father[rootX] = rootY; 
            sets--; 
        }
    }
};