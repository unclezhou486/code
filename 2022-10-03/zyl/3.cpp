#include <bits/stdc++.h>

using namespace std;
const int N=1e3+10;

int t;

int n,m;
char a[N][N];
int d[N];
int d1[N<<1];

void bfs(int j,int k){
	int dx[4]={0,0,1,-1};
	int dy[4]={1,-1,0,0};
	queue<pair<int,int> >q;
	q.push({j,k});
	d[j][k]=1;
	while(q.size()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int x2=x+dx[i],y2=y+dy[i];
			if(x2<1||x2>n||y2<1||y2>m||a[x2][y2]=='G'||d[x2][y2]) continue;
			d[x2][y2]=d[x][y]+1;
			d1[d[x2][y2]]++;
			q.push({x2,y2});
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cnt=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				if(a[i][j]=='#') cnt++;		
			}
		}
		bool f=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='#'){
					bfs(i,j);
					f=0;
					break;
				}
			}
			if(!f) break;
		}
		int cnt=0;
		for(int i=1;i<n+m;i++){
			for(int j=1;j<i;j++){
				
			}
		}
	}	
}