#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#define ll long long
#define Max 202
using namespace std;
int n,m,a,b;
int in_deg[Max],ans[Max];
vector<int> vec[Max];
priority_queue<int,vector<int>,less<int> > q;//从大到小
void init()
{
    memset(ans,0,sizeof(ans));
    memset(in_deg,0,sizeof(in_deg));
    for(int i=1;i<=n;i++)
        vec[i].clear();
    while(!q.empty()) q.pop();
}
void toposort()
{
    for(int i=1;i<=n;i++)
    {
        if(in_deg[i]==0) q.push(i);
    }
    int cnt=0;
    int weigh=n;
    while(!q.empty()){
        int u=q.top(); q.pop();
        cnt++;
        ans[u]=weigh--;
        for(int v=0;v<vec[u].size();v++)
        {
            in_deg[vec[u][v]]--;
            if(in_deg[vec[u][v]]==0)
            {
                q.push(vec[u][v]);
            }
        }
    }
    if(cnt!=n)
        printf("-1\n");
    else
    {
        printf("%d",ans[1]);
        for(int i=2;i<=cnt;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            vec[b].push_back(a);
            in_deg[a]++;
        }
        toposort();
    }
    return 0;
}
/*
有n个球，分别编号为1到n，并且每个球有对应的重量，输入时，每行输入的两个数，表示“编号”为a的球的重量小于“编号为b的球的重量”，分别输出1到n编号对应的球的重量，尽量保证编号较小的球重量也较小。注意仔细理解题：读入的时候是球的编号，输出的是对应编号的球的重量，看到dicuss区的数据才发现自己题目都读错了。
*/

/*
3

5 4
5 1
4 2
1 3
2 3

10 5
4 1
8 1
7 8
4 1
2 8


5 4
1 4
4 2
5 3
3 2
ans:
2 4 5 3 1        逆向建图
5 1 6 2 7 8 3 4 9 10  重边的话就输出 -1

标签小的重量尽量小

1~n编号的盒子，放1~n重量的球，给出m对盒子装的小球之间大小的关系，输出1~n编号盒子重量，要求编号越小的盒子，放的重量越小。
*/