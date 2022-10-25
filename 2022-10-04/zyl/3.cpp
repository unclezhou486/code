#include <bits/stdc++.h>

using namespace std;
const int N=1e5+10;

int n,m,q;
int a,b;
int ans;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

bool v[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		for(int i=m;i>=1;i--){
			if(!(a%i)){
				v[i]=1;
			}
		}
		
	}
}