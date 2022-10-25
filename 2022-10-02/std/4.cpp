#include<bits/stdc++.h>
using namespace std;

pair<int,int> a[111111];
int t, n, k;
int g[111111];

int main() {
	scanf("%d", &t);
	n = 0;
	for (int i = 1; i <= t; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x >= 0 && y >= 0) {
			n += 1;
			a[n] = make_pair(x, y);
		}
	}

	sort(a + 1, a + 1 + n);

	k = 0;
	for (int i = 1; i <= n; ++i) {
		int y = a[i].second;
		if (k == 0 || y >= g[k]) {
			k += 1;
			g[k] = y;
		} else {
			int k2 = upper_bound(g + 1, g + 1 + k, y) - g;
			g[k2] = y;
		}
	}

	printf("%d\n", k);
	return 0;
}