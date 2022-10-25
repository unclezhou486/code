#include<bits/stdc++.h>
using namespace std;
const int N=50;
int main()
{
	int T,tot,h[N]={},m[N]={},s[N]={};
	int a1,b1,a2,b2,a3,b3;
	scanf("%d",&T);
	while(T--)
	{
		tot=0;
		scanf("%d/%d %d/%d %d/%d",&a1,&b1,&a2,&b2,&a3,&b3);
		for(int hh=0;hh<12;++hh)
			for(int mm=0;mm<60;++mm)
				for(int ss=0;ss<60;++ss)
				{
					int x1=hh*3600+mm*60+ss,x2=mm*720+ss*12,x3=ss*720;
					int d1=abs(x1-x2),d2=abs(x1-x3),d3=abs(x2-x3);
					d1=min(d1,360*120-d1);
					d2=min(d2,360*120-d2);
					d3=min(d3,360*120-d3);
					if(d1*b1==a1*120 && d2*b2==a2*120 && d3*b3==a3*120)
					{
						++tot;
						h[tot]=hh,m[tot]=mm,s[tot]=ss;
					}
				}
		printf("%d\n",tot);
		for(int i=1;i<=tot;++i)
			printf("%02d:%02d:%02d\n",h[i],m[i],s[i]);
	}
}