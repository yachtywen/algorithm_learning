#include<vector>
using namespace std;
void floyd() {
    // 核心：必须最先枚举跳板 k
    int n;
    //dist[i][j]表示从i到j的距离，
    //在最初始的时候表示相邻两点间的距离，要是不相邻为INT_MAX
    vector<vector<int>>dist;
    //k为bridge
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 防止溢出并更新最短路径
                if (dist[i][k] != INT_MAX &&
                    dist[k][j] != INT_MAX &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    //算法核心
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}