/*
注意此题不是保证字典序，而是要最小的尽量在前面。
对于有m组限制即a必须在b前面出去，而对于那些没有限制的就必须按照标号从小到大出去，也就是说假设有三个人，3号必须在1号前面除去，2号没限制，那么出去的顺序为3 1 2，为了满足这个需求，反向建图+拓扑排序+优先队列+逆序输出
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
priority_queue<int,vector<int>,less<int> > q;//从大到小
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
            vec[b].push_back(a);//反向建图
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
在主要的拓扑排序的基础上又添加了一个要求：编号最小的节点要尽量排在前面；在满足上一个条件的基础上，编号第二小的节点要尽量排在前面；在满足前两个条件的基础上，编号第三小的节点要尽量排在前面……依此类推。（注意，这和字典序是两回事，不能够混淆。）
*/

/*
是反向建边，点大的优先级高，用拓扑排序+优先队列，逆向输出序列即可。

根据每对限制，可确定拓扑序列，但此时的拓扑序列可能有多个（没有之间关系的点的顺序不定）。本题要求较小的点排到前面，则可确定序列。

（1）如果点a和点b有直接和简接的拓扑关系，那么a和b的先后顺序可有拓扑排序确定。

（2）如果点a和点b没有直接和简接的拓扑关系，那么a和b的先后顺序由a和b所能到达的点的确定。

如：

1

3 2

3 1

3 1

应输出结果为 3 1 2

点3 和 点2 没有直接的拓扑关系，但是3到达最小点为1，2到达最小点为2。

综合（1）和（2）本题需要逆向处理。

PS：欧拉回路的路径输出也是逆向输出的。

*/