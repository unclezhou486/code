#include <bits/stdc++.h>
#define int long long
using namespace std;

int t,y,l;

bool check(int x){
	int c=y;
	string s;
	int b=0;
	while(c){
		if(c%x>=10) return 0; 
		char d=(c%x)+48;
		s+=d;
		c/=x;
	}
	for(int i=s.size()-1;i>=0;i--){
		b=(b<<1)+(b<<3)+s[i]-48;
	}
	if(b<l) return 0;
	else return 1;
}

signed main(){
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>y>>l;
		int l=10,r=y;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(mid)){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		cout<<l<<'\n';
	}
}