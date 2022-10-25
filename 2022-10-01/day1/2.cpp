#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
int f[1001][1001], ind[1001], n, m, k, a, b;
std::vector<int> edge[1001], cost[1001];
std::queue<int> q;
int topo(int a, int b) {
	for (int i = 1; i <= n; i++) if (i != a && !ind[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0, iBound = edge[u].size(); i < iBound; i++) {
			int v = edge[u][i]; ind[v]--, (ind[v] == 0 && v != a && (q.push(v), 0));
		}
	}
	memset(f, 0x3f, sizeof f);
	f[a][0] = 0, q.push(a);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0, iBound = edge[u].size(); i < iBound; i++) {
			int v = edge[u][i], w = cost[u][i];
			for (int j = 0; j < k; j++) f[v][(j + w) % k] = std::min(f[v][(j + w) % k], f[u][j] + w);
			ind[v]--, (ind[v] == 0 && (q.push(v), 0));
		}
	}
	return f[b][0] == 0x3f3f3f3f ? -1 : f[b][0];
}
int main() {
	scanf("%d%d%d%d%d", &n, &m, &k, &a, &b);
	for (int i = 1; i <= m; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		edge[u].push_back(v), cost[u].push_back(w), ind[v]++;
	}
	printf("%d\n", topo(a, b));
} 