#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    static const int MAXN = 100001;
    int father[MAXN];
    void build(int n) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    bool unite(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            father[fx] = fy;
            return true;
        }
        else {
            return false;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
            });
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
            });
        build(n);
        vector<bool>ans(queries.size());
        for (int i = 0, j = 0; i < queries.size(); i++) {
            while (j < edgeList.size() && edgeList[j][2] < queries[i][2]) {
                unite(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            int p = queries[i][0];
            int q = queries[i][1];
            ans[queries[i][3]] = find(p) == find(q) ? true : false;
        }
        return ans;
    }
    
};