#include <bits/stdc++.h>
#define Max 100005
using namespace std;
struct Node{
	int layer;
	int sum; //商品数目 只有retailer有
	vector<int> child; //孩子 
}node[Max];
int n, k, v;
int leaf[Max];
double p, r;
void bfs(int rt){
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(rt);
	node[rt].layer = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = 0; i < node[u].child.size(); i++){
			node[node[u].child[i]].layer = node[u].layer + 1; 
			q.push(node[u].child[i]); 
		} 
	}
}
int main(){
	memset(leaf, 0, sizeof(leaf));
	cin >> n >> p >> r;
	for(int i = 0; i < n; i++){
		cin >> k;
		if(k == 0){
			cin >> node[i].sum;
			leaf[i] = 1;
		}else {
			for(int j = 0; j < k; j++){
				cin >> v;
				node[i].child.push_back(v);
			}
		}
	}
	bfs(0);
	double ans = 0, price;
//	cout << "---==" << p << endl;
	for(int i = 0; i < n; i++){
		if(leaf[i]){
			price = p * pow(1+r/100.0, node[i].layer);
//			cout << "----> " << node[i].sum << " " << node[i].layer <<" "<<price<< endl;
			ans += price * node[i].sum;
		}
	}
	cout << fixed << setprecision(1) << ans << endl;
	return 0;
}
