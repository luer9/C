/*
n ����Tom�������������
n�� n������  0 or 1
�����i���е�j��������1 ���������˳���ش�����i�ƶ�������j,��������Ͳ���˳���ش�����i�ƶ�������j

���
k ������С��������
���� 2k �� ��
��һ�� m���������е���������
�ڶ��� ����m������ ����m�������˳��
�����ж����ͬ�Ĵ𰸣��κ�һ��������
*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#define ll long long
#define Max 1002 
using namespace std;
int mapp[Max][Max],ans[Max];
int n;
inline void read(int& a)
{
    char c;
    while(!(((c=getchar())>='0')&&(c<='9')));a=c-'0';
    while(((c=getchar())>='0')&&(c<='9'))(a*=10)+=c-'0';
}
void Insert(int arv[],int &len,int index,int key)
{
    if(index>len) index=len;
    len++;
    for(int i=len-1;i>=0;i--)
    {
        if(i!=index&&i)
        {
            arv[i]=arv[i-1];
        }else
        {
            arv[i]=key;
            return ;
        }
    }
}
void Hamilton(int n)
{
    int ansi=1;
    ans[ansi++]=1;
    //��һ�����,ֱ�Ӱѵ�ǰ����ӵ�����ĩβ
    for(int i=2;i<=n;i++)
    {
        if(mapp[i][ans[ansi-1]]==1)
        {
            ans[ansi++]=i;
        }else{
            int flag=0;
            //��ǰ���дӺ���ǰ�ҵ�һ�����������ĵ�j,ʹ�ô���<Vj,Vi>��<Vi,Vj+1>
            for(int j=ansi-2;j>0;j--)
            {
                if(mapp[i][ans[j]]==1)
                {
                    flag=1;
                    Insert(ans,ansi,j+1,i);
                    break;
                }
            }
            //����˵�����е㶼�ڽ��Ե�i,��Ѹõ�ֱ�Ӳ��뵽�����׶�
            if(!flag)
            {
                Insert(ans,ansi,1,i);
            }
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(mapp,0,sizeof(mapp));
        memset(ans,0,sizeof(ans));
        int op;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                // scanf("%d",&op);  //TLE
                read(op);
                if(op==1)
                mapp[j][i]=1;
            }
        }
        printf("%d\n%d\n",1,n);
        Hamilton(n);
        for(int i=1;i<=n;i++){
            printf(i==1?"%d":" %d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}