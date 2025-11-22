#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    static const int MAXN = 50001;
    int q[MAXN];
    int h, t;
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int n = tasks.size();
        int s = workers.size();
        int l = 0, r = min(n, s);
        int ans = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(tasks,workers,0,m-1,s-m,s-1,strength,pills)) {
                ans = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return ans;

    }
    bool check(vector<int>& tasks, vector<int>& workers,int tl,int tr,int wl,int wr, int strength, int pills) {
        h = t = 0;
        int count = 0;
        for (int i = wl, j = tl; i <= wr; i++) {
            while (j <= tr && tasks[j] <= workers[i]) {
                q[t++] = j++;
            }
            if (h < t && tasks[q[h]] <= workers[i]) {
                h++;
            }
            else {
                while (j <= tr && tasks[j] <= workers[i] + strength) {
                    q[t++] = j++;
                }
                if (h < t) {
                    count++;
                    t--;
                }
                else {
                    return false;
                }
            }
        }
        return count <= pills;
    }
};