/*
���⣺�ϰ��Ա�������� 
n��Ա����m�й�ϵ
ÿ������ a��b  
Ҫ��a�Ĺ��ʱ���� b ��
��͹����� 888
���ϰ�һ��������Ҫ�����ٹ���
����������������˵�����Ļ� �����-1
*/
#include <bits/stdc++.h>
#define ll long long
#define Max 10002
using namespace std;
int n,m;
int mon[Max];//�ֲ� �൱��ÿ����888���ʵļӳ�
int in_deg[Max];
vector<int> vec[Max];
queue<int>q;
void init(int nn)//ע���ʼ��
{
    for(int i=0;i<=nn;i++)
    {
        vec[i].clear();
    }
    memset(in_deg,0,sizeof(in_deg));
    while(!q.empty()) q.pop();
    memset(mon,0,sizeof(mon));
}
int topsort()
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
        int u=q.front();
        q.pop();
        cnt++;
        for(int v=0;v<vec[u].size();v++)
        {
            in_deg[vec[u][v]]--;
            if(!in_deg[vec[u][v]])
            {
                q.push(vec[u][v]);
                mon[vec[u][v]]=max(mon[u]+1,mon[vec[u][v]]);
                //money�ֲ�
            }
        }
    }
    return cnt==n;
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        init(n);
        int u,v;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            vec[v].push_back(u);// ���򽨱�
            in_deg[u]++;
        }
        ll ans=0;
        if(topsort())
        {
        
            for(int i=1;i<=n;i++)
            {
              //  cout<<i<<": "<<mon[i]<<endl;
                ans+=(888+mon[i]);
            }
            cout<<ans<<endl;
        }else 
        {
            cout<<"-1"<<endl;
        }
    }return 0;
}
/*
4 4 1 2 2 3 1 4 3 4
3 2 1 2 1 3
3 1 1 2

7 7
1 2
2 6
3 2
3 4
4 5
5 6
7 6


*/