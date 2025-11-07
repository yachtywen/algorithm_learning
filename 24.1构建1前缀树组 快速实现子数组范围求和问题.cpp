#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int compute(vector<int>& arr, int aim) {
    unordered_map<int, int> map;
    map[0] = -1;
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        //表示在map中存在sum-aim这个键-->为True
        if (map.find(sum - aim) != map.end()) {
            ans = max(ans, i - map[sum - aim]);
        }
        //表示在map中不存在sum
        if (map.find(sum) == map.end()) {
            map[sum] = i;
        }
    }
    return ans;
}
int main() {
    int N, aim;
    cin >> N >> aim;
    vector<int>arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int ans = compute(arr, aim);
    cout << ans;
}