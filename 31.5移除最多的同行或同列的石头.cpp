#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<int, int>rowFirst;
    unordered_map<int, int>colFirst;
    vector<int>father;
    int sets;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        build(n);
        for (int i = 0; i < n; i++) {
            if (rowFirst.find(stones[i][0]) == rowFirst.end()) {
                rowFirst[stones[i][0]] = i;
            }
            else {
                unite(i, rowFirst[stones[i][0]]);
            }
            if (colFirst.find(stones[i][1]) == colFirst.end()) {
                colFirst[stones[i][1]] = i;
            }
            else {
                unite(i, colFirst[stones[i][1]]);
            }
        }
        return n - sets;
    }
    void build(int n) {
        father.resize(n);
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
        sets = n;
    }
    int find(int i) {
        if (father[i] != i) {
            father[i] = find(father[i]);
        }
        return father[i];
    }
    void unite(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            father[fx] = fy;
            sets--;
        }
    }
};