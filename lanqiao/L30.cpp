#include <iostream>
#include <string.h>

using namespace std;

int L,N,l;//L为长串长度，N为长串1的个数,l为短串长度
char a[50];//存储短串（从1开始）
int flag=0;//成功匹配的次数，0代表失败，2及以上代表歧义

void dfs(int num_1, int len, int i)//num_1为目前译码的1的数量，len为目前译码得到的长码长度，i为需要译码的起始位置
{
    if(i==l)//当短码最后一位为译码开始的地方
    {
        dfs(num_1+a[i]-'0',len+1,i+1);
        return;
    }
    if(i>l)//一轮译码结束
    {
        if(len==L && num_1==N)
        {
            flag++;
        }
        return;
    }
    if(len>L || num_1>N || flag>=2) return;//显然如果发生以上三种情况，可以退出
    if(a[i]=='0')//0的话只要继续下一步译码，num_1不变
    {
        dfs(num_1,len+1,i+1);
        return;
    }
    //下面讨论a[i]==1的情况
    if(a[i-1]=='1') return;//和0110、010匹配，因为之前已经算过了
    long long temp=0;//计算i~j这一块二进制几个1，虽然题目中最多16*1024*8=131072位，在int范围内，但在译码的时候可能超过
    if(a[i+1]=='0')//类似010
    {
        dfs(num_1+1,len+1,i+1);
        //不写return是因为如果单独译码不行，还要继续连着后面译码，例如10100可以译成101111和1111100，因此还需要参加for循环
    }
    if(a[i+1]=='1' && a[i+2]!='1')//类似0110，这里不用=='0'是因为可能溢出
    {
        dfs(num_1+2,len+2,i+2);
    }
    //三或三个以上的1同时出现，或者0110解释成11不能满足条件
    for(int j=i;j<=l;j++)
    {
        temp*=2;//左移一位
        temp+=a[j]-'0';//译码完成
        if(temp+num_1>N || temp+len>L) break;//失败
        if(temp>j-i+1 && a[j+1]!='1')//省略了010的重复搜索
            dfs(num_1+temp,len+temp,j+1);//i~j的一次译码，a[j+1]为0或溢出
    }
}


int main()
{
    cin>>L>>N;
    cin>>(a+1);
    l=strlen(a+1);
    dfs(0,0,1);
    if(flag==1) cout<<"YES"<<endl;
    if(!flag) cout<<"NO"<<endl;
    if(flag>=2) cout<<"NOT UNIQUE"<<endl;
    return 0;
}


