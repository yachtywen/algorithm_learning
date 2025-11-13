#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int>surplus(gas.size());
        for (int i = 0; i < gas.size(); i++) {
            surplus[i] = gas[i] - cost[i];
        }
        int l = 0, r = 0;
        while(l<surplus.size()) {
            int sur = 0;
            while (sur+surplus[r%surplus.size()]>=0) {
                sur += surplus[r % surplus.size()];
                r++;
                if (r - l == surplus.size()) return l;
            }
            l = r + 1;
            r = l;
        }
         return -1;
    }
};
int main() {
    Solution sol;
    vector<int> gas = { 1, 2, 3, 4, 5 };
    vector<int> cost = { 3, 4, 5, 1, 2 };
    cout << sol.canCompleteCircuit(gas, cost) << endl;  // Êä³ö: 3
    return 0;
}