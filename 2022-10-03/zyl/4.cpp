#include <bits/stdc++.h>

using namespace std;
const int N=2e5+10;

int n,m;
int qu;
int a[N],b[N];
struct node{
	int l,r,s,t;
}q[N];

bool cmp(node a,node b){
	return a.r<b.r;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>qu;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=qu;i++){
		cin>>q[i].l>>q[i].r>>q[i].s>>q[i].t;
	}
	sort(q+1,q+1+qu,cmp);
}