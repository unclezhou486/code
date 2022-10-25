#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
//#define int long long
#define PII pair<int,int>
#define rep(k,l,r) for(int k=l;k<=r;++k)
#define per(k,r,l) for(int k=r;k>=l;--k)
#define cl(f,x) memset(f,x,sizeof(f))
using namespace std;
const int N=3e2+5;
int a[N][N],n,m;
bool check(int x1,int y1,int x2,int y2) {
	int len=x1-x2+1;
	rep(i,x2,x1) {
		rep(j,y2,y1) {
			if(a[i][j]!=a[x1-(i-x2)][y1-(j-y2)])
				return false;
		}
	}
	return true;
}
bool check2(int k) {
	rep(i,k,n) {
		rep(j,k,m) {
			if(check(i,j,i-k+1,j-k+1))
				return true;
		}
	}
	return false;
}
signed main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) {
		rep(j,1,m) {
			char c; cin>>c; a[i][j]=c^48;
		}
	}
	int ans=-1,l=2,r=(n+1)/2;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check2(mid*2-1))
			ans=max(ans,mid*2-1),l=mid+1;
		else
			r=mid-1;
	}
	l=1; r=n/2;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check2(mid*2))
			ans=max(ans,mid*2),l=mid+1;
		else
			r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
} 