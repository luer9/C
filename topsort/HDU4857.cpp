/*
ע����ⲻ�Ǳ�֤�ֵ��򣬶���Ҫ��С�ľ�����ǰ�档
������m�����Ƽ�a������bǰ���ȥ����������Щû�����Ƶľͱ��밴�ձ�Ŵ�С�����ȥ��Ҳ����˵�����������ˣ�3�ű�����1��ǰ���ȥ��2��û���ƣ���ô��ȥ��˳��Ϊ3 1 2��Ϊ������������󣬷���ͼ+��������+���ȶ���+�������
*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define Max 30002
using namespace std;
int n,m,a,b;
int in_deg[Max],ans[Max];
vector<int> vec[Max];
priority_queue<int,vector<int>,less<int> > q;//�Ӵ�С
//priority_queue<Type, Container, Functional>
void init()
{
    while(!q.empty()) q.pop();
    memset(in_deg,0,sizeof(in_deg));
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++){
        vec[i].clear();
    }
}
void toposort()
{
    for(int i=1;i<=n;i++)
    {
        if(in_deg[i]==0)
        {
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty())
    {
        int u=q.top();q.pop();
        ans[cnt++]=u;
        for(int v=0;v<vec[u].size();v++)
        {
            in_deg[vec[u][v]]--;
            if(in_deg[vec[u][v]]==0)
            {
                q.push(vec[u][v]);
            }
        }
    }
    if(cnt!=n) {
       // cout<<"-1"<<endl;
        printf("-1\n");
    }else
    {
       // cout<<ans[0];
        printf("%d",ans[cnt-1]);
        for(int i=cnt-2;i>=0;i--)
            printf(" %d",ans[i]);
           // cout<<" "<<ans[i];
        printf("\n");
    }
    
}
int main()
{
    // ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n>>m;
        scanf("%d%d",&n,&m);
        init();
        for(int i=0;i<m;i++)
        {
            //cin>>a>>b;
            scanf("%d%d",&a,&b);
            vec[b].push_back(a);//����ͼ
            //vec[a].push_back(b);
            in_deg[a]++;
        }
        toposort();
    }
    return 0;
}
/*
1
3 1
3 1
------
3 1 2
*/
/*
����Ҫ����������Ļ������������һ��Ҫ�󣺱����С�Ľڵ�Ҫ��������ǰ�棻��������һ�������Ļ����ϣ���ŵڶ�С�Ľڵ�Ҫ��������ǰ�棻������ǰ���������Ļ����ϣ���ŵ���С�Ľڵ�Ҫ��������ǰ�桭���������ơ���ע�⣬����ֵ����������£����ܹ���������
*/

/*
�Ƿ��򽨱ߣ��������ȼ��ߣ�����������+���ȶ��У�����������м��ɡ�

����ÿ�����ƣ���ȷ���������У�����ʱ���������п����ж����û��֮���ϵ�ĵ��˳�򲻶���������Ҫ���С�ĵ��ŵ�ǰ�棬���ȷ�����С�

��1�������a�͵�b��ֱ�Ӻͼ�ӵ����˹�ϵ����ôa��b���Ⱥ�˳�������������ȷ����

��2�������a�͵�bû��ֱ�Ӻͼ�ӵ����˹�ϵ����ôa��b���Ⱥ�˳����a��b���ܵ���ĵ��ȷ����

�磺

1

3 2

3 1

3 1

Ӧ������Ϊ 3 1 2

��3 �� ��2 û��ֱ�ӵ����˹�ϵ������3������С��Ϊ1��2������С��Ϊ2��

�ۺϣ�1���ͣ�2��������Ҫ������

PS��ŷ����·��·�����Ҳ����������ġ�

*/