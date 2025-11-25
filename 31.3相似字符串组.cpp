#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int>father;
    int sets;
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        father.resize(n);
        build(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (find(i) != find(j)) {
                    int diff = 0;
                    for (int k = 0; k < strs[0].size(); k++) {
                        if (strs[i][k] != strs[j][k])diff++;
                    }
                    if (diff == 2||diff==0)unite(i, j);
                }
            }
        }
        return sets;
    }
    void build(int m) {
        for (int i = 0; i < m; i++) {
            father[i] = i;
        }
        sets = m;
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void unite(int x, int y) {
        int fy = find(y);
        int fx = find(x);
        if (fx != fy) {
            father[fx] = fy;
        }
        sets--;
    }
};