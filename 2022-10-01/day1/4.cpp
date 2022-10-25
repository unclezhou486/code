#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100001, N2 = 52, inf = INT_MAX;
int n, k, m;
ll a[N];
struct node{
	int l, r, cnt, ans, pre2[N2], suf2[N2];
	ll pre[N2], suf[N2], d;
}t[4 * N];
void pushup(int id, int l, int r) {
	t[id].d = (t[l].d | t[r].d);
	for (int i = 1; i <= t[l].cnt; ++i) {
		t[id].pre[i] = t[l].pre[i];
		t[id].pre2[i] = t[l].pre2[i];
	}
	int tmp = t[l].cnt;
	ll last = t[l].d;
	for (int i = 1; i <= t[r].cnt; ++i) {
		if ((last | t[r].pre[i]) != last) {
			t[id].pre[++tmp] = (last | t[r].pre[i]);
			t[id].pre2[tmp] = t[r].pre2[i];
			last |= t[r].pre[i];
		}
	}
	t[id].cnt = tmp;
	for (int i = 1; i <= t[r].cnt; ++i) {
		t[id].suf[i] = t[r].suf[i];
		t[id].suf2[i] = t[r].suf2[i];
	}
	tmp = t[r].cnt; last = t[r].d;
	for (int i = 1; i <= t[l].cnt; ++i) {
		if ((last | t[l].suf[i]) != last) {
			t[id].suf[++tmp] = (last | t[l].suf[i]);
			t[id].suf2[tmp] = t[l].suf2[i];
			last |= t[l].suf[i];
		}
	}
	t[id].ans = inf;
	int left = 0;
	if (t[l].ans != inf) t[id].ans = t[l].ans;
	if (t[r].ans != inf) t[id].ans = min(t[id].ans, t[r].ans);
	for (int i = t[l].cnt; i >= 0; --i) {
		while ((t[l].suf[i] | t[r].pre[left]) < (1ll << k) - 1 && left < t[r].cnt) ++left;
		if ((t[l].suf[i] | t[r].pre[left]) < (1ll << k) - 1) break;
		if (left == 0) t[r].pre2[left] = t[l].r;
		t[id].ans = min(t[id].ans, t[r].pre2[left] - t[l].suf2[i] + 1);
	}
}
void build(int id, int l, int r) {
	t[id].l = l;
	t[id].r = r;
	if (l == r) {
		t[id].cnt = 1;
		t[id].pre[1] = t[id].suf[1] = t[id].d = (1ll << (a[l] - 1));
		t[id].pre2[1] = t[id].suf2[1] = l;
		if (k == 1) t[id].ans = 1;
		else t[id].ans = inf;
		return;
	}
	int mid = (l + r) >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	pushup(id, id * 2, id * 2 + 1);
}
void change(int id, int x, int v) {
	if (t[id].l == x && t[id].r == x) {
		t[id].pre[1] = t[id].suf[1] = t[id].d = (1ll << (v - 1));
		return;
	}
	int mid = (t[id].l + t[id].r) >> 1;
	if (x <= mid) change(id * 2, x, v);
	else change(id * 2 + 1, x, v);
	pushup(id, id * 2, id * 2 + 1);
}
int main() {
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	build(1, 1, n);
	while (m--) {
		int op, x, y;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &x, &y);
			change(1, x, y);
		} else {
			if (t[1].ans == inf) printf("-1\n");
			else printf("%d\n", t[1].ans);
		}
	}
	return 0;
} 