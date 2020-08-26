// minimum number of stops.
//�ҳ�һ��·�ߣ�ʹ�ö��κθ����������յ㣬�����ҳ���;��ͣվ���ٵ�·�ߣ�
//�����ͣվһ���࣬��ȡ��Ҫ������·�������ٵ�·�� 
#include <bits/stdc++.h>
#define Max 10002
#define inf 0x3f3f3f3f
using namespace std;
vector<vector<int> > v(Max);
int vis[Max], minCnt, minTransfer, st, endd;
map<int, int> line;//������վ����· 
vector<int> path, tempPath;
//ת��վ�ĸ��� 
int transferCnt(vector<int> &a){
	int cnt = -1, preLine = 0;
	for(int i = 1; i < a.size(); i++){
		if(line[a[i-1]*10000+a[i]] != preLine) cnt++;
		preLine = line[a[i-1]*10000+a[i]];
	}
	return cnt;
} 
void dfs(int id, int cnt){
	if(id == endd && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))){
		minCnt = cnt;
		minTransfer = transferCnt(tempPath);
		path = tempPath;
	}
	if(id == endd) return;
	for(int i = 0; i < v[id].size(); i++){
		if(!vis[v[id][i]]){
			vis[v[id][i]] = 1;
			tempPath.push_back(v[id][i]);
			dfs(v[id][i], cnt+1);
			vis[v[id][i]] = 0;
			tempPath.pop_back(); 
		}
	}
}
int main(){
	int n, m, k, pre, temp;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
        scanf("%d%d", &m, &pre);
		for(int j = 1; j < m; j++){
			scanf("%d", &temp);
			v[pre].push_back(temp);
			v[temp].push_back(pre);
			line[pre*10000 + temp] = line[temp*10000 + pre] = i;
			pre = temp;
		}
	}
	
    scanf("%d", &k);
	for(int  i = 0; i < k; i++){
		
        scanf("%d%d", &st, &endd);
		minCnt = inf, minTransfer = inf;
		tempPath.clear();
		tempPath.push_back(st);
		vis[st] = 1;
		dfs(st, 0);
		vis[st] = 0;
        printf("%d\n", minCnt);
		int preLine = 0; //ǰһ����·�ı�� 
		int preTransfer = st;
		for(int j = 1; j < path.size(); j++){
			if(line[path[j-1]*10000+path[j]] != preLine){
				if(preLine != 0)
					printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
				preLine = line[path[j - 1] * 10000 + path[j]];
				preTransfer = path[j - 1];
			} 
		} 
		 printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, endd);
	}
	return 0;
} 
