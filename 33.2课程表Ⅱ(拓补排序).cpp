#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>queue(numCourses);
        vector<int>indegree(numCourses,0);
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        int l = 0, r = 0;
        int cnt = 0;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)queue[r++] = i;
        }
        while (l < r) {
            int cur = queue[l++];
            cnt++;
            for (int i = 0; i < graph[cur].size(); i++) {
                if (--indegree[graph[cur][i]] == 0)queue[r++] = graph[cur][i];
            }
        }
        if (cnt == numCourses) {
            return queue;
        }
        else {
            return {};
        }
    }
};