#include <bits/stdc++.h>
#define Max 100022
using namespace std;
struct Node{
	int addr, data, nex;
}node[Max];
int vis[Max];
int st, n;
int main(){
	memset(vis, 0, sizeof(vis));	
	scanf("%d%d",&st,&n);
	for(int i = 0; i < n; i++){
		Node temp;
		scanf("%d%d%d",&temp.addr,&temp.data,&temp.nex);
		node[temp.addr].data = temp.data;
		node[temp.addr].addr = temp.addr;
		node[temp.addr].nex = temp.nex; 		
	}
	int ind = st;
	vector<Node> lis, del;
	while(ind != -1){
		if(!vis[abs(node[ind].data)]){
			lis.push_back(node[ind]);
			vis[abs(node[ind].data)] = 1;
		}else {
			del.push_back(node[ind]);
		}
		ind = node[ind].nex;
	}
	for(int i = 0; i < lis.size(); i++){
		if(i != lis.size() - 1) {
			printf("%05d %d %05d\n",lis[i].addr,lis[i].data,lis[i+1].addr);
		}else {
			printf("%05d %d -1\n",lis[i].addr,lis[i].data);
		}
	}
	
	for(int i = 0; i < del.size(); i++){
		if(i != del.size() - 1) {
			printf("%05d %d %05d\n",del[i].addr,del[i].data,del[i+1].addr);
		}else {
			printf("%05d %d -1\n",del[i].addr,del[i].data);
		}
	}
	return 0;
}
