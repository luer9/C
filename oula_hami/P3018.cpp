/*
They intend to visit every road , and every road must be visited for exact one time.
No two roads will be the same,and there is no road connecting the same town.
Ŀ�꣺����ÿһ�����򣬲���ÿ��·(��)����һ����·ֻ��һ��
һ�����鱻�ֳɼ���С�� �����ʳ��� 
�����ٷּ����飬����ʵ��Ŀ��
�ͱ��磺һ�ʻ����⣺��Ҫ���ʲ��ܰ����б߶�����
hint:û��һ��·��ĳһ��������ӣ�С���Ͼͻ�����������

ans=ŷ��·�ĸ���+��ͨͼ�ж���Ϊ��ĸ���/2
why? https://blog.csdn.net/u013480600/article/details/30285541
*/
#include <bits/stdc++.h>
#define Max 100002
using namespace std;
int n,m,u,v,cnt;
int deg[Max],odd[Max],fa[Max];
int vis[Max];
vector<int> vec;//�洢���ڵ� �����ж��ж��ٸ���ͨ��
void init()
{
    vec.clear();
    for(int i=1;i<=n;i++) fa[i]=i;
    memset(deg,0,sizeof(deg));
    memset(odd,0,sizeof(odd));
    memset(vis,0,sizeof(vis));
}
int Find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=Find(fa[x]);
}
void mix(int x,int y)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy)
    {
        fa[fx]=fy;
    }
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        init();
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            deg[u]++,deg[v]++;
            mix(u,v);
        }
        //����ͨ��
        for(int i=1;i<=n;i++)
        {
            int fi=Find(i);
            if(!vis[fi])
            {
                vec.push_back(fi);// �м������Ⱦ��м�����ͨ��
                vis[fi]=1;
            }
            if(deg[i]%2) odd[fi]++; // �洢������fi��ͼ�е�������ĵ�
        }
        cnt=0;
        vector<int>::iterator it;
        for(it=vec.begin();it!=vec.end();it++){
          //  cout<<"-> "<<(*it)<<endl;
            if(deg[(*it)]==0) continue; //������Ŷ
            if(odd[(*it)]==0) cnt++;//����������ڵ���ͨ������û�� ��ȵ�
            else cnt+=odd[(*it)]/2;
        }
        cout<<cnt<<endl; 
    }
    return 0;
}
/*
3 3
1 2
2 3
1 3

4 2
1 2
3 4

4 7 
1 2 
1 3 
1 4 
2 3 
2 4 
3 4 
3 3 
 
4 5 
1 2 
2 3 
4 4 
4 4 
4 4 

�������ͨ������һ�������ĵ�,��Ȼֻ��Ҫ0��.
�������ͨ������һ��ŷ��ͼ���ŷ��ͼ,ֻ��Ҫ1��.
��ͨ��������һ��(��)ŷ��ͼʱ,��Ҫ(��ͼ�������ȵĵ���Ŀ/2)��
*/
