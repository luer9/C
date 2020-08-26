/*
ŷ��·��
���⣺�����϶�д�˸��֣����ӱ��밴��һ����˳�����У�����Ĺ�����ÿ�����ʵĿ�ͷ����һ�����ʵĽ�β��ĸ��ͬ
Ҫ�ж����е������Ƿ��ܰ��������Ĺ�������
���鼯+ŷ��· �ж�
ps:���鼯�ж���ͨ��
���ﹹ��ͼ��������ͼ ----->
����ͼ�жϴ���ŷ����·��ŷ��ͨ·��������
ֻ�������������㣺һ������ȵ��ڳ���+1����һ�������=����-1������ÿ������ȶ����ڳ��ȣ�����ÿ������ȶ����ڳ��ȡ�
*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#define ll long long
#define Max 100005
using namespace std;
string s;
int n,m;
int vis[30],fa[30];//vis�ж���ĸ�Ƿ����,fa�������ڲ��鼯
int out[30],in[30];//��ÿ����ĸ����Ⱥͳ���
struct Node
{
    int u,v;
}edge[Max];
void init()
{
    memset(vis,0,sizeof(vis));
    memset(out,0,sizeof(out));
    memset(in,0,sizeof(in));
    for(int i=0;i<26;i++)fa[i]=i;
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
int If_connect()
{
    //�ϲ�
    for(int i=0;i<n;i++){
        int u=edge[i].u,v=edge[i].v;
        if(u!=v&&Find(u)!=Find(v))
        {
            mix(u,v);
        }
    }
    //�ж���ͨ��
    int f=-1,k;
    for(k=0;k<26;k++)
    {
        if(!vis[k]) continue;
        if(f==-1) f=k; //f��¼��һ�����ڵ��ַ�
        else if(Find(f)!=Find(k)) break;//���Ȳ�һ�� ˵������ͨ
    }
    if(k<26) return 0;
    return 1;
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        init();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            int u=s[0]-'a',v=s[s.length()-1]-'a';
            edge[i].u=u,edge[i].v=v;
            vis[u]=vis[v]=1;
            out[u]++,in[v]++; // ����  ���
            //ÿ����ĸ����һ����
        }
        bool flag=true;
        int cnt1=0,cnt2=0;
        for(int i=0;i<26;i++){
            if(!vis[i]) continue; 
            //��Ⱥͳ��Ȳ���
            if(abs(out[i]-in[i])>1){flag=false;break;}
            if(out[i]-in[i]==1)//����б�����һ��
            {
                cnt1++; 
                if(cnt1>1){flag=false; break; }
            }
            if(out[i]-in[i]==-1)//����б�����һ��
            {
                cnt2++;
                if(cnt2>1) {flag=false;break; }
            }
        }
        /*
        ��������ȶ���ȣ����߳�����������
        ���ඥ��ĳ�������ȶ���ȣ���������������һ������ĳ���-���==1��
        ��һ������-���==-1��
        */
        if(cnt1!=cnt2) flag=false; 
        if(!If_connect()) flag=false;
        if(flag) cout<<"Ordering is possible."<<endl;
        else cout<<"The door cannot be opened."<<endl;

    }
    return 0;
} 
