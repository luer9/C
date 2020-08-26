/*
题意：n个点m条无向边,输出一条哈密顿回路
every knight has at least (N + 1) / 2 other knights as his close friends.这句话其实是保证了哈密顿回路的存在性
基于定理Dirac：当所有点相连的点的个数大于N/2时，一定可以构造出一条哈密顿回路
STEP1:先找两个相邻点s-t，扩充出一条链直到到不能扩充为止。
STEP2:这时如果s-t不相邻，在链上找一点vi满足s与next[vi]相邻并且vi与t相邻，链转化为s-vi-t-next[vi]-s
STEP3:如果链中的点不足N个，就在环上开一个新口继续加点，重复STEP1~3即可。
*/
#include <bits/stdc++.h>
#define Max 202
using namespace std;
int n, m;
int mp[Max][Max],vis[Max];
int S, T, cnt, ans[Max];
//转置
void _reverse(int l,int r) {
	while (l<r)
		swap(ans[l++],ans[r--]);
}
//扩展
void expand() {
	while(1) {
		bool flag = false;
		for (int i=1; i<=n && false == flag; i++)
			if (!vis[i] && mp[T][i])
			{
				ans[cnt++]=i;
				T=i;
				flag = true;
				vis[i] = 1;
			}
		if (!flag) break;
	}
}
void hamiltun(int Start){
	memset(vis, 0, sizeof(vis));
	S = Start;
	for(T=2; T<=n; T++) //随意找两个相邻的节点S和T
		if (mp[S][T]) break;
	cnt = 0;
	ans[cnt++]=S;
	ans[cnt++]=T;
	vis[S] = vis[T] = true;
	while (1)
	{
		expand(); //在它们基础上扩展出一条尽量长的没有反复节点的路径:步骤1
	//	cout<<"---> "<<S<<" "<<T<<endl;
		_reverse(0,cnt-1);
	//	cout<<"---> "<<S<<" "<<T<<endl;
		swap(S,T);
	//	cout<<"---> "<<S<<" "<<T<<endl;
		expand(); //在它们基础上扩展出一条尽量长的没有反复节点的路径
		//写两次expand()的原因是 分别以S,T作为起点开始扩充，两端都扩充到不能再扩充
		int mid=0;//交换分界点
		if (!mp[S][T]) //若S与T不相邻,能够构造出一个回路使新的S和T相邻
		{
			//设路径S→T上有k+2个节点,依次为S,v1,v2…… vk和T.
			//能够证明存在节点vi,i∈[1,k),满足vi与T相邻,且vi+1与S相邻
			for (int i=1; i<cnt-2; i++)
				if (mp[ans[i]][T] && mp[ans[i+1]][S]){mid=i+1; break;}
			//把原路径变成S→Vi→T→Vi+1→S,即形成了一个回路
			_reverse(mid,cnt-1);
			T=ans[cnt-1];
		}
		if (cnt==n) break;
		//如今我们有了一个没有反复节点的回路.假设它的长度为N,则汉密尔顿回路就找到了
		//否则,因为整个图是连通的,所以在该回路上,一定存在一点与回路以外的点相邻那么从该点处把回路断开,就变回了一条路径,再依照步骤1的方法尽量扩展路径
		for (int i = 1, j; i <= n; i++)
			if (!vis[i])
			{
				for (j=1; j<cnt-1; j++)
					if (mp[ans[j]][i]) break;
				if (mp[ans[j]][i])
				{T=i; mid=j;break;}
			}
		S=ans[mid-1];
		_reverse(0,mid-1);
		_reverse(mid,cnt-1);
		ans[cnt++]=T;
		vis[T]=true;
	}
}
 
int main() {
	while (cin>>n>>m) {
		memset(mp, 0, sizeof mp);
		for (int i = 1, u, v; i <= m; i++) {
			scanf("%d %d",&u, &v);
			mp[u][v] = mp[v][u] = 1;
		}
		hamiltun(1);
		for (int i = 0; i < cnt; i++)
			printf("%d%c", ans[i], i==cnt-1?'\n':' ');
	}
	return 0;
}
