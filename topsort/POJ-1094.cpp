/*
we will give you a set of relations of the form A < B and ask you to determine whether a sorted order has been specified or not.
1��������һ����ϵ��ʱ����ȫ��ȷ�����й�ϵ -> Sorted sequence determined after x relations: %&^%.
2�������ڼ���ʱ�ܷ���ì�ܣ����� -> Inconsistency found after x  relations.
3��û��ì�ܵ��Ǹ����Ĺ�ϵ�޷�ȷ����ϵ -> Sorted sequence cannot be determined.

������Ǹ���һϵ�еĹ�ϵ��������������Ĺ�ϵ�д�С������һ������������Ĺ�ϵ�з�����ͻ�����������ͻ����һ����������Եõ�һ���������Ŀ�������ڼ�����ϵ����ȷ��˳��
ע�⣺֮ǰ�Ѿ�ȷ���˷���Լ�������У���ô֮���ٸ�����ì�ܵ���������Ч�� 
eg:--->
5 5
A<B
B<C
C<D
D<E
E<A
output:
Sorted sequence determined after 4 relations: ABCDE
----------------------------------------------------------------------
��Ϊ���ֻ��26����ĸ��������ôд�����ᳬʱ��
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n,m,cnt;
int in_deg[30];//�ڵ��������
int in_degTemp[30];//��ʱ�ڵ�������� Ϊ�˱�֤����һ����ϵ�� ǰ�� �ڵ�ȵ�ͳһ
char Ans[30];//�������Ľ��
vector<int>vec[30]; //��ͼ
queue<int>q; //����
void init()
{
    //26��Ӣ����ĸ
    for(int i=0;i<26;i++)
    {
        vec[i].clear();
    }
    while(!q.empty()) q.pop();
    memset(in_deg,0,sizeof(in_deg));
    memset(in_degTemp,0,sizeof(in_degTemp));
    memset(Ans,0,sizeof(Ans));
    
}
int topsort()
{
    //ÿ������һ����ϵҪ�ж�һ���Ƿ��н����
    //in_degTemp�� ��¼ÿһ�μӱߺ�-��-�ı��-����  in_deg���ܸ�
    for(int i=0;i<n;i++)
    {
        if(!in_deg[i])
        {
            q.push(i);
        }
    }
    bool unSure=false;//��ȷ��(3)������ı��
    cnt=0;
    while(!q.empty())
    {
        //һ�������еĵ�û���漰(�ȽϵĹ�ϵ��)�����Ϊ0�ĵ��Ȼ����1,��϶�����˵�� �еĵ��޷�ȷ����ϵ
        if(q.size()>1) unSure=true;
        int u=q.front();
        q.pop();
        Ans[cnt++]=u+'A';
        for(int v=0;v<vec[u].size();v++)
        {
            in_deg[vec[u][v]]--;
            if(!in_deg[vec[u][v]])
            {
                q.push(vec[u][v]);
            }
        }
    }
    if(cnt<n)//���ڻ�
    {
        return 3;
    }
    if(unSure)//��ȷ��
    {
        return 2;
    }
    return 1;// ȷ����
}
int main()
{

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        if(n==0&&m==0) break;
        char op[3];
        bool flag=false;
        int step=0,ans;
        for(int i=0;i<m;i++)
        {
            scanf("%s",op);
            //�Ѿ��н���� �Ͳ���Ҫ�жϺ�ߵĹ�ϵ ���� ��Ҫ������������
            if(flag) continue;
            vec[op[0]-'A'].push_back(op[2]-'A');
            in_deg[op[2]-'A']++;
            memcpy(in_degTemp,in_deg,sizeof(in_deg));
            ans=topsort();//ÿ��һ����ϵ ���˴���һ�� ��������ʱ�����һ�£���ǰ������
            memcpy(in_deg,in_degTemp,sizeof(in_degTemp));
            if(ans!=2){
                step=i+1;
                flag=true;
            }//��������޽���Ļ� ��ô���� ��·�����н��
        }
        if(ans==1){
            Ans[cnt]='\0';
            printf("Sorted sequence determined after %d relations: %s.\n",step,Ans);
        }else if(ans==2)
        {
            printf("Sorted sequence cannot be determined.\n");
        }else if(ans==3)
        {
            printf("Inconsistency found after %d relations.\n", step);
        }
    }
    return 0;
}
