#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int>indegree(n,0);
        vector<int>deep(n,0);
        for (int i = 0; i < n; i++) {
            indegree[favorite[i]]++;
        }
        vector<int>queue(n);
        int r = 0, l = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)queue[r++]=i;
        }
        while (l < r) {
            int cur = queue[l++];
            int next = favorite[cur];
            deep[next] = max(deep[next], deep[cur] + 1);
            if (--indegree[next] == 0)queue[r++] = next;
        }
        int sumOfSmallRings = 0;
        int bigRings = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] != 0) {
                int rSize = 1;
                int start = i;
                indegree[start] = 0;
                for (int j = favorite[start]; j != start; j=favorite[j]) {
                    rSize++;
                    indegree[j] = 0;
                }
                if (rSize == 2) {
                    sumOfSmallRings += (2 + deep[start] + deep[favorite[start]]);
                }
                else {
                    bigRings = max(bigRings, rSize);
                }
            }
        }
        return max(sumOfSmallRings, bigRings);
    }
};