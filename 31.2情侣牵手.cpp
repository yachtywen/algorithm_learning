#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    static const int MAXN = 31;
    int father[MAXN];
    int sets;
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int couplesCount = n / 2;
        build(couplesCount);
        for (int i = 0; i < n; i+=2) {
            int firstPersonGroup = row[i] / 2;
            int secondPersonGroup = row[i + 1] / 2;
            unite(firstPersonGroup, secondPersonGroup);
        }
        return couplesCount-sets;
    }
    void build(int m) {
        for (int i = 0; i < m; i++) {
            father[i] = i;
        }
        sets = m;
    }
    int find(int i) {
        if (i != father[i]) {
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