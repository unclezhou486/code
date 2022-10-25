#include<bits/stdc++.h>
using namespace std;

const int p = 998244353;
int fac(int x, int y, int p) { // x ^ y % p;
	int ans = 1;
	for(; y; y = y/2) {
		if (y & 1) ans = 1LL * ans * x % p;
		x = 1LL * x * x % p;
	}
	return ans;
}

int inv(int x, int p) {
	return fac(x, p - 2, p);
}

string s1, s2;
int main() {
	cin >> s1 >> s2;
	int n = 0, m = 0;
	for (int i = 0; i < s1.length(); ++i) {
		n = (1LL * n * 10 + s1[i] - '0') % p;
	}
	for (int i = 0; i < s2.length(); ++i) {
		m = (1LL * m * 10 + s2[i] - '0') % p;
	}
	//cout << n << " " << m << endl;
	cout << ((1 - 1LL * m * inv(1LL * n * n % p, p)) % p + p) % p << endl;
	return 0;
}