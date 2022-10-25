#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct Solver {
private:
  static const int N = 1000000;
  int n, nume, col[N + 1], h[N + 1], belong[N + 1], dist[N + 1];
  struct Edge {
    int v, nxt;
  } e[N << 1];

  void add_edge(int u, int v) {
    e[++ nume].v = v, e[nume].nxt = h[u], h[u] = nume;
    e[++ nume].v = u, e[nume].nxt = h[v], h[v] = nume;
  }

  void input() {
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
      char c; cin >> c;
      col[i] = c == 'R';
    }
    for (int i = 1; i < n; ++ i) {
      int a, b;
      cin >> a >> b;
      add_edge(a, b);
    }
  }

  void init(int t, int fa) {
    if (col[t] == col[fa]) belong[t] = belong[fa];
    else belong[t] = t;
    for (int i = h[t]; i; i = e[i].nxt)
      if (e[i].v != fa) init(e[i].v, t);
  }

  void dfs(int t, int fa, int depth) {
    dist[t] = depth;
    for (int i = h[t]; i; i = e[i].nxt)
      if (e[i].v != fa)
        if (belong[t] == belong[e[i].v]) dfs(e[i].v, t, depth);
        else dfs(e[i].v, t, depth + 1);
  }

  void process() {
    memset(dist, 0, sizeof dist);
    dfs(1, 0, 1);
    int ma = -1, p = 0;
    for (int i = 1; i <= n; ++ i)
      if (dist[i] > ma) {
        ma = dist[i], p = i;
      }
    memset(dist, 0, sizeof dist);
    dfs(p, 0, 1);
    ma = -1;
    for (int i = 1; i <= n; ++ i) ma = max(ma, dist[i]);
    cout << (ma >> 1) << endl;
  }

public:
  void solve() {
    input(), col[0] = -1, init(1, 0), process();
  }
} solver;

int main() {
//  freopen("xc.in ", "r", stdin);
//  freopen("xc.out", "w", stdout);
  solver.solve();
  return 0;
} 