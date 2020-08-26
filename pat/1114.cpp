/*
好久没写并查集了…… 
输出： 
家庭成员最小的id，家庭成员人数，人均房产套数 ，人均房产面积 
*/
 
#include <bits/stdc++.h>
#define Max 10010
using namespace std;
struct people{
	int id, father, mother;
	int setNum;
	double area;
	people(){
		father = mother = -1;
		area = setNum = 0;
	}
}peo[Max]; 
struct family{
	int id;
	int peoNum; //家庭总人数
	int setNum;//房子套数
	double areaNum; //总面积 
	double setAvg, areaAvg; //人均房套，人均房面 
	int flag;
}fam[Max];
int fa[Max], n, k, vis[Max];
void init(){
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < Max; i++){
		fa[i] = i;
		fam[i].flag = 0;
	}
}
bool cmp(family a, family b){
	if(a.areaAvg != b.areaAvg){
		return a.areaAvg > b.areaAvg;
	}
	return a.id < b.id;
}
int Find(int x){
	while(x != fa[x])
		x = fa[x];
	return x;
}
void mix(int a,int b){
	int Fa = Find(a);
	int Fb = Find(b);
	if(Fa > Fb){
		fa[Fa] = Fb;
	}else fa[Fb] = Fa;
}
int main(){
	
	int cnt = 0;
	init();
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d",&peo[i].id, &peo[i].father, &peo[i].mother, &k);
		vis[peo[i].id] = 1;
		if(peo[i].father != -1) {
			vis[peo[i].father] = 1;
			mix(peo[i].id, peo[i].father);
		}
		if(peo[i].mother != -1){
			vis[peo[i].mother] = 1;
			mix(peo[i].id, peo[i].mother);
		}
		int childId;
		for(int j = 0; j < k; j++){
			scanf("%d", &childId);
			vis[childId]= 1;
			mix(peo[i].id, childId);
		}
		scanf("%d %lf",&peo[i].setNum, &peo[i].area);
	}
	for(int i = 0; i < n; i++){
		int rt = Find(peo[i].id);
		fam[rt].id = rt;
		fam[rt].setNum += peo[i].setNum;
		fam[rt].areaNum += peo[i].area;
		fam[rt].flag = true;
	}
	//找family size 
	for(int i = 0; i < Max; i++){
		if(vis[i]){
			fam[Find(i)].peoNum++;
		}
		if(fam[i].flag){
			cnt++;
		} 
	}
	for(int i = 0; i < Max; i++){
		if(fam[i].flag){
			fam[i].areaAvg = fam[i].areaNum*1.0 / fam[i].peoNum;
			fam[i].setAvg = fam[i].setNum*1.0 / fam[i].peoNum;
		}
	}
	sort(fam, fam+Max, cmp);
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++){
		printf("%04d %d %.3lf %.3lf\n", fam[i].id, fam[i].peoNum, fam[i].setAvg, fam[i].areaAvg);
	}
	return 0;
}
