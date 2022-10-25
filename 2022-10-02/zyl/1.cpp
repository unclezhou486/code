#include <bits/stdc++.h>

using namespace std;

const int mod=998244353;

long long qmi(long long a,long long b){
	a=a%mod;
	long long res=1;
	while(b){
		if(b&1) res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

long long read(){
	long long x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48,x%=mod,c=getchar();
	return x;
}
long long n,m;
int main(){
	n=read(),m=read();
	cout<<((((n*n%mod)-m)%mod+mod)%mod*qmi(n*n,mod-2))%mod;
}