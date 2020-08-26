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
//����
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
/*
�����������Ѿ����ɹ��ܶ٣����ڼ���������㣬
�ɾ���ͼ֪��������������ǰ��������϶����Թ��ɹ��ܶ٣�Ȼ����ĸ��㣬�������������������е㡣
*/
void Hamilton(int n)
{
    int ansi=1;
    ans[ansi++]=1;//��һ���������ܶ�ͼ������
    for(int i=2;i<=n;i++)//������δ������ܶ�ͼ�ĵ�
    {
        //if(mapp[i][ans[ansi-1]]==1)    //��һ�����,ֱ�Ӱѵ�ǰ�����ӵ�����ĩβ
        if(mapp[ans[ansi-1]][i]==1)  //������Ҳ����
        {
            ans[ansi++]=i;
        }else{
            int flag=0;
            //��ǰ����(���ܶ�ͼ�ı�������)�Ӻ���ǰ�ҵ�һ�����������ĵ�j,ʹ�ô���<Vj,Vi>��<Vi,Vj+1>
            for(int j=ansi-2;j>0;j--)
            {
               // if(mapp[i][ans[j]]==1)
                if(mapp[ans[j]][i]==1)
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
                if(op) mapp[i][j]=1;
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