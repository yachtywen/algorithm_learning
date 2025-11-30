#include<iostream>
#include<vector>
using namespace std;
//假设最多11个点
const int MAXN = 11;
// 边的最大数量
// 只有链式前向星方式建图需要这个数量
// 注意如果无向图的最大数量是m条边，数量要准备m*2 (因为无向边等于两条有向边)
const int MAXM = 21;
//1.邻接矩阵方式建图
int graph1[MAXN][MAXN];
//2.邻接表方式建图
vector<vector<pair<int, int>>> graph2;
//3.链式前向星方式建图
//存储以i为起点的第一条边的编号
int head[MAXN];
//存储编号为ei的边的下一条同起点的边的编号
int next_edge[MAXM];
//存储编号为ei的边指向的终点
int to[MAXM];
//编号为ei的边的权重
int weight[MAXM];
int cnt;
void build(int n) {
	//1.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph1[i][j] = 0;
		}
	}
	//2.
	graph2.clear();
	graph2.resize(n + 1);
	//3.
	cnt = 1;
	memset(head, 0, sizeof(head));
}
// 链式前向星加边核心逻辑
// 类似于头插法建立链表
void addEdge(int u, int v, int w) {
	// u -> v , 边权重是w
	next_edge[cnt] = head[u]; // 当前边的next指向旧的head
	to[cnt] = v;              // 记录终点
	weight[cnt] = w;          // 记录权重
	head[u] = cnt++;          // 更新head，使其指向当前最新加入的边，cnt自增
}
// 三种方式建立有向图带权图
void directGraph(const vector<vector<int>>& edges) {
	for (const auto& edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int w = edge[2];

		// 1. 邻接矩阵建图
		graph1[u][v] = w;

		// 2. 邻接表建图
		// push_back 自动将 {v, w} 构造成 pair
		graph2[u].push_back({ v, w });

		// 3. 链式前向星建图
		addEdge(u, v, w);
	}
}
// 三种方式建立无向图带权图
void undirectGraph(const vector<vector<int>>& edges) {
	for (const auto& edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int w = edge[2];

		// 1. 邻接矩阵建图 (双向赋值)
		graph1[u][v] = w;
		graph1[v][u] = w;

		// 2. 邻接表建图 (双向添加)
		graph2[u].push_back({ v, w });
		graph2[v].push_back({ u, w });

		// 3. 链式前向星建图 (双向调用addEdge)
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
}
// 打印遍历结果
void traversal(int n) {
	cout << "邻接矩阵遍历 :" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << graph1[i][j] << " ";
		}
		cout << endl;
	}

	cout << "邻接表遍历 :" << endl;
	for (int i = 1; i <= n; i++) {
		cout << i << "(邻居、边权) : ";
		// 遍历 i 的邻接表
		for (const auto& edge : graph2[i]) {
			cout << "(" << edge.first << "," << edge.second << ") ";
		}
		cout << endl;
	}

	cout << "链式前向星 :" << endl;
	for (int i = 1; i <= n; i++) {
		cout << i << "(邻居、边权) : ";
		// 注意这个for循环，链式前向星的标准遍历方式
		// ei = head[i] 获取起点边的编号
		// ei > 0 判断是否还有边 (0代表空)
		// ei = next_edge[ei] 跳转到下一条边
		for (int ei = head[i]; ei > 0; ei = next_edge[ei]) {
			cout << "(" << to[ei] << "," << weight[ei] << ") ";
		}
		cout << endl;
	}
}