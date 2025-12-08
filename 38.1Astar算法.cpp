#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <chrono> // 用于高精度计时

using namespace std;

// A*算法模版（对数器验证）
// 包含Dijkstra与A*的对比实现

// 方向数组技巧
// 0:上 (-1, 0)
// 1:右 (0, 1)
// 2:下 (1, 0)
// 3:左 (0, -1)
// 使用 move_dir[i] 和 move_dir[i+1] 可以依次取出上述四个方向的偏移量
const int move_dir[] = { -1, 0, 1, 0, -1 };

// 自定义比较器结构体，用于优先队列 (PriorityQueue)
// C++的 priority_queue 默认是大根堆，为了实现小根堆（距离最小的在顶部），
// 我们需要定义 "大于" 逻辑，这样较大的元素会沉到底部，较小的浮上来。
struct Comp {
    // 比较两个 vector<int>，我们依据 index=2 的值（权值/代价）
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    }
};

// 曼哈顿距离 (Manhattan Distance)
// 适用于只能上下左右移动的网格图
// f(n) = g(n) + h(n) 中的 h(n) 启发式函数
int f1(int x, int y, int targetX, int targetY) {
    return (abs(targetX - x) + abs(targetY - y));
}
//A星算法核心内容（预估函数）
// 对角线距离 (Diagonal Distance)
// 适用于允许8方向移动的图（本题未用到，但保留作为模版参考）
int f2(int x, int y, int targetX, int targetY) {
    return max(abs(targetX - x), abs(targetY - y));
}

// 欧式距离 (Euclidean Distance)
// 真实几何距离（本题未用到）-->勾股定理
double f3(int x, int y, int targetX, int targetY) {
    return sqrt(pow(targetX - x, 2) + pow(targetY - y, 2));
}

/**
 * Dijkstra算法实现
 * grid[i][j] == 0 代表障碍
 * grid[i][j] == 1 代表道路
 * 返回从(startX, startY)到(targetX, targetY)的最短距离
 * * 核心逻辑：优先处理 "当前离起点最近" 的节点。
 */
int minDistance1(const vector<vector<int>>& grid, int startX, int startY, int targetX, int targetY) {
    // 起点或终点本身就是障碍，直接不可达
    if (grid[startX][startY] == 0 || grid[targetX][targetY] == 0) {
        return -1;
    }
    int n = grid.size();
    int m = grid[0].size();

    // distance数组记录从起点到(i,j)的当前最短距离，初始化为无穷大
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    // 起点到自己的距离为1 (根据题目逻辑，包含起点本身算1步)
    distance[startX][startY] = 1;

    // visited数组记录节点是否已经弹出过堆（是否已确定最短路）
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // 小根堆
    // 元素格式: {行(x), 列(y), 当前距离(cost)}
    priority_queue<vector<int>, vector<vector<int>>, Comp> heap;
    heap.push({ startX, startY, 1 });

    while (!heap.empty()) {
        vector<int> cur = heap.top();
        heap.pop();
        int x = cur[0];
        int y = cur[1];

        // 如果该点已经处理过，跳过
        if (visited[x][y]) {
            continue;
        }
        visited[x][y] = true;

        // 发现终点，直接返回距离（因为是Dijkstra，第一次弹出终点时即为最短路）
        if (x == targetX && y == targetY) {
            return distance[x][y];
        }

        // 遍历上下左右四个方向
        for (int i = 0; i < 4; i++) {
            int nx = x + move_dir[i];
            int ny = y + move_dir[i + 1];

            // 越界检查 + 障碍检查 + 是否已访问 + 松弛操作(Relaxation)
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[nx][ny] == 1 && !visited[nx][ny] &&
                distance[x][y] + 1 < distance[nx][ny]) {

                // 更新最短距离
                distance[nx][ny] = distance[x][y] + 1;
                // 将新节点加入堆，权重为"起点到该点的真实距离"
                heap.push({ nx, ny, distance[nx][ny] });
            }
        }
    }
    return -1; // 无法到达
}

/**
 * A* (A-Star) 算法实现
 * * 核心逻辑：优先处理 "当前离起点距离 + 预估离终点距离" 最小的节点。
 * f(n) = g(n) + h(n)
 * g(n): 起点到当前点的真实代价 (distance[x][y])
 * h(n): 当前点到终点的预估代价 (Heuristic function)
 */
int minDistance2(const vector<vector<int>>& grid, int startX, int startY, int targetX, int targetY) {
    if (grid[startX][startY] == 0 || grid[targetX][targetY] == 0) {
        return -1;
    }
    int n = grid.size();
    int m = grid[0].size();

    // distance 依然只记录真实的 g(n)
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    distance[startX][startY] = 1;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // 小根堆
    // 元素格式: {行, 列, f(n)}
    // 注意：这里的第三个参数不再单纯是距离，而是 f(n) = g(n) + h(n)
    priority_queue<vector<int>, vector<vector<int>>, Comp> heap;

    // 初始入堆：g(start)=1, h(start)=f1(...)
    heap.push({ startX, startY, 1 + f1(startX, startY, targetX, targetY) });

    while (!heap.empty()) {
        vector<int> cur = heap.top();
        heap.pop();
        int x = cur[0];
        int y = cur[1];

        if (visited[x][y]) {
            continue;
        }
        visited[x][y] = true;

        // 找到终点
        if (x == targetX && y == targetY) {
            return distance[x][y];
        }

        // 遍历四周
        for (int i = 0; i < 4; i++) {
            int nx = x + move_dir[i];
            int ny = y + move_dir[i + 1];

            // 判断条件与Dijkstra一致
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[nx][ny] == 1 && !visited[nx][ny] &&
                distance[x][y] + 1 < distance[nx][ny]) {

                // 更新真实距离 g(n)
                distance[nx][ny] = distance[x][y] + 1;

                // 关键点：入堆时的优先级使用 f(n)
                // f(nx, ny) = g(nx, ny) + h(nx, ny)
                // g(nx, ny) = distance[nx][ny]
                // h(nx, ny) = f1(nx, ny, targetX, targetY)
                int priority = distance[nx][ny] + f1(nx, ny, targetX, targetY);
                heap.push({ nx, ny, priority });
            }
        }
    }
    return -1;
}

// 辅助函数：生成随机网格用于测试
vector<vector<int>> randomGrid(int n) {
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 生成 [0, 1) 的随机浮点数
            double p = rand() / (double)RAND_MAX;
            if (p < 0.3) {
                grid[i][j] = 0; // 30% 障碍
            }
            else {
                grid[i][j] = 1; // 70% 通路
            }
        }
    }
    return grid;
}

int main() {
    // 设置随机种子
    srand((unsigned)time(0));

    int len = 100;
    int testTime = 10000;

    cout << "功能测试开始" << endl;
    for (int i = 0; i < testTime; i++) {
        // 随机生成地图大小和内容
        int n = (rand() % len) + 2;
        vector<vector<int>> grid = randomGrid(n);
        int startX = rand() % n;
        int startY = rand() % n;
        int targetX = rand() % n;
        int targetY = rand() % n;

        // 验证两个算法结果是否一致
        int ans1 = minDistance1(grid, startX, startY, targetX, targetY);
        int ans2 = minDistance2(grid, startX, startY, targetX, targetY);

        if (ans1 != ans2) {
            cout << "出错了!" << endl;
            // 可以在这里打印出错的 grid 和坐标以便调试
            return 0;
        }
    }
    cout << "功能测试结束" << endl;

    cout << "性能测试开始" << endl;
    // 生成一个 4000x4000 的大地图进行性能对比
    vector<vector<int>> grid = randomGrid(4000);
    int startX = 0;
    int startY = 0;
    int targetX = 3900;
    int targetY = 3900;

    // 测试 Dijkstra
    auto start = chrono::high_resolution_clock::now();
    int ans1 = minDistance1(grid, startX, startY, targetX, targetY);
    auto end = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "运行Dijkstra算法结果: " << ans1 << ", 运行时间(毫秒) : " << duration1 << endl;

    // 测试 A*
    start = chrono::high_resolution_clock::now();
    int ans2 = minDistance2(grid, startX, startY, targetX, targetY);
    end = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "运行A*算法结果: " << ans2 << ", 运行时间(毫秒) : " << duration2 << endl;

    cout << "性能测试结束" << endl;

    return 0;
}