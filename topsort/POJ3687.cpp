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
priority_queue<int,vector<int>,less<int> > q;//�Ӵ�С
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
��n���򣬷ֱ���Ϊ1��n������ÿ�����ж�Ӧ������������ʱ��ÿ�����������������ʾ����š�Ϊa���������С�ڡ����Ϊb��������������ֱ����1��n��Ŷ�Ӧ�����������������֤��Ž�С��������Ҳ��С��ע����ϸ����⣺�����ʱ������ı�ţ�������Ƕ�Ӧ��ŵ��������������dicuss�������ݲŷ����Լ���Ŀ�������ˡ�
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
2 4 5 3 1        ����ͼ
5 1 6 2 7 8 3 4 9 10  �رߵĻ������ -1

��ǩС����������С

1~n��ŵĺ��ӣ���1~n�������򣬸���m�Ժ���װ��С��֮���С�Ĺ�ϵ�����1~n��ź���������Ҫ����ԽС�ĺ��ӣ��ŵ�����ԽС��
*/