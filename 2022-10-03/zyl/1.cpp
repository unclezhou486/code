#include <bits/stdc++.h>

using namespace std;

int t,y,l,a;

int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
	cin>>t;
	int cnt=0;
	int la=0;
	while(t--){
		cin>>y>>l;
		int x=10;
		int ans=10;
		while(x){
			bool f=1;
			x++;
			int c=y;
			int b=0;
			string s;
			while(c){
				if((c%x)>=10) {f=0;}
				char d=(c%x)+'0';
				s+=d;
				c/=x;
			}
			reverse(s.begin(),s.end());
			for(int i=0;i<s.size();i++){
				b=b*10+s[i]-48;
			}
			//cout<<x<<'\n';
			//cout<<b<<'\n';
			if(b<l) break;
			if(f) ans=x;
		}
		cout<<ans<<'\n';
	}
}

/*

2 
32 20 
2016 100 

*/