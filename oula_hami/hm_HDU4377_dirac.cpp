/*
���⣺n����m�������,���һ�����ܶٻ�·
every knight has at least (N + 1) / 2 other knights as his close friends.��仰��ʵ�Ǳ�֤�˹��ܶٻ�·�Ĵ�����
���ڶ���Dirac�������е������ĵ�ĸ�������N/2ʱ��һ�����Թ����һ�����ܶٻ�·
STEP1:�����������ڵ�s-t�������һ����ֱ������������Ϊֹ��
STEP2:��ʱ���s-t�����ڣ���������һ��vi����s��next[vi]���ڲ���vi��t���ڣ���ת��Ϊs-vi-t-next[vi]-s
STEP3:������еĵ㲻��N�������ڻ��Ͽ�һ���¿ڼ����ӵ㣬�ظ�STEP1~3���ɡ�
*/
#include <bits/stdc++.h>
#define Max 202
using namespace std;
int n, m;
int mp[Max][Max],vis[Max];
int S, T, cnt, ans[Max];
//ת��
void _reverse(int l,int r) {
	while (l<r)
		swap(ans[l++],ans[r--]);
}
//��չ
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
	for(T=2; T<=n; T++) //�������������ڵĽڵ�S��T
		if (mp[S][T]) break;
	cnt = 0;
	ans[cnt++]=S;
	ans[cnt++]=T;
	vis[S] = vis[T] = true;
	while (1)
	{
		expand(); //�����ǻ�������չ��һ����������û�з����ڵ��·��:����1
	//	cout<<"---> "<<S<<" "<<T<<endl;
		_reverse(0,cnt-1);
	//	cout<<"---> "<<S<<" "<<T<<endl;
		swap(S,T);
	//	cout<<"---> "<<S<<" "<<T<<endl;
		expand(); //�����ǻ�������չ��һ����������û�з����ڵ��·��
		//д����expand()��ԭ���� �ֱ���S,T��Ϊ��㿪ʼ���䣬���˶����䵽����������
		int mid=0;//�����ֽ��
		if (!mp[S][T]) //��S��T������,�ܹ������һ����·ʹ�µ�S��T����
		{
			//��·��S��T����k+2���ڵ�,����ΪS,v1,v2���� vk��T.
			//�ܹ�֤�����ڽڵ�vi,i��[1,k),����vi��T����,��vi+1��S����
			for (int i=1; i<cnt-2; i++)
				if (mp[ans[i]][T] && mp[ans[i+1]][S]){mid=i+1; break;}
			//��ԭ·�����S��Vi��T��Vi+1��S,���γ���һ����·
			_reverse(mid,cnt-1);
			T=ans[cnt-1];
		}
		if (cnt==n) break;
		//�����������һ��û�з����ڵ�Ļ�·.�������ĳ���ΪN,���ܶ��ٻ�·���ҵ���
		//����,��Ϊ����ͼ����ͨ��,�����ڸû�·��,һ������һ�����·����ĵ�������ô�Ӹõ㴦�ѻ�·�Ͽ�,�ͱ����һ��·��,�����ղ���1�ķ���������չ·��
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
