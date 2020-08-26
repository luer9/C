/*
错误原因： 没有判断图连通
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N,M;
int du[1010];
void init()
{
	memset(du,0,sizeof(du));
}
int main()
{
	while(scanf("%d",&N),N)
	{
		init();
		scanf("%d",&M);
		for(int i=0;i<M;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			du[a]++;
			du[b]++;
		}
		int f=1;
		for(int i=1;i<=N;i++)
		{
			if(du[i]%2||du[i]==0)
			{
				printf("0\n");
				f=0;
				break;
			}
		}
		if(f)
		printf("1\n");
	}
	return 0;
}