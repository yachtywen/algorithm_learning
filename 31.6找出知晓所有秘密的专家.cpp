#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int>father;
    vector<bool>secret;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
            });
        build(n, firstPerson);
        int m = meetings.size();
        for (int l = 0,r; l < m; ) {
            r = l;
            while (r + 1 < m && meetings[l][2] == meetings[r + 1][2]) {
                r++;
            }
            for (int i = l; i <= r; i++) {
                unite(meetings[i][0], meetings[i][1]);
            }
            for (int i = l; i <= r; i++) {
                int a = meetings[i][0];
                int b = meetings[i][1];
                if (!secret[find(a)])father[a] = a;
                if (!secret[find(b)])father[b] = b;
            }
            l = r + 1;
        }
        vector<int>ans;
        for (int i = 0; i < n; i++) {
            if (secret[find(i)])ans.push_back(i);
        }
        return ans;
    }
    void build(int n,int fp) {
        father.resize(n);
        secret.resize(n);
        for (int i = 0; i < n; i++) {
            father[i] = i;
            secret[i] = false;
        }
        secret[0] = true;
        secret[fp] = true;
        unite(0, fp);
    }
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void unite(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            father[fx] = fy;
            secret[fy] = secret[fx] == true ? true : secret[fy];
        }
    }
};