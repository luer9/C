/*
we will give you a set of relations of the form A < B and ask you to determine whether a sorted order has been specified or not.
1、处理到第一个关系的时候能全部确定所有关系 -> Sorted sequence determined after x relations: %&^%.
2、处理到第几个时能发现矛盾（环） -> Inconsistency found after x  relations.
3、没有矛盾但是给出的关系无法确定关系 -> Sorted sequence cannot be determined.

题意就是给你一系列的关系，让你从他给出的关系中从小到大排一个序，如果给出的关系中发生冲突，输出发生冲突的那一步，如果可以得到一个序，输出题目给出到第几个关系才能确定顺序。
注意：之前已经确定了符合约束的序列，那么之后再给出的矛盾的条件是无效的 
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
因为最多只有26个字母，所以怎么写都不会超时。
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n,m,cnt;
int in_deg[30];//节点入度数组
int in_degTemp[30];//临时节点入度数组 为了保证加入一个关系后 前后 节点度的统一
char Ans[30];//最后排序的结果
vector<int>vec[30]; //存图
queue<int>q; //队列
void init()
{
    //26个英文字母
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
    //每次输入一个关系要判断一次是否有结果，
    //in_degTemp是 记录每一次加边后-度-改变的-数组  in_deg不能改
    for(int i=0;i<n;i++)
    {
        if(!in_deg[i])
        {
            q.push(i);
        }
    }
    bool unSure=false;//不确定(3)的情况的标记
    cnt=0;
    while(!q.empty())
    {
        //一旦出现有的点没有涉及(比较的关系中)，入度为0的点必然大于1,则肯定可以说明 有的点无法确定关系
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
    if(cnt<n)//存在环
    {
        return 3;
    }
    if(unSure)//不确定
    {
        return 2;
    }
    return 1;// 确定了
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
            //已经有结果了 就不需要判断后边的关系 但是 还要读入所有数据
            if(flag) continue;
            vec[op[0]-'A'].push_back(op[2]-'A');
            in_deg[op[2]-'A']++;
            memcpy(in_degTemp,in_deg,sizeof(in_deg));
            ans=topsort();//每加一个关系 拓扑处理一次 并且用临时数组存一下，当前入度情况
            memcpy(in_deg,in_degTemp,sizeof(in_degTemp));
            if(ans!=2){
                step=i+1;
                flag=true;
            }//如果不是无结果的话 那么就是 回路或者有结果
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
