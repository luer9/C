#include <bits/stdc++.h>
#define Max 100002
using namespace std;
struct Node{
	int add;
	int data;
	int nex;
}node[Max];
int st, n, k;
vector<Node> v;  //<0 
vector<Node> v1; // < k
vector<Node> v2; 
int main(){
	int ad;
	scanf("%d %d %d",&st, &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d",&ad);
		scanf("%d %d",&node[ad].data, &node[ad].nex);
		node[ad].add = ad;
	}
	int p = st;
	while(p != -1){
		if(node[p].data < 0) {
			v.push_back(node[p]);
		}else if(node[p].data >= 0 && node[p].data <= k){
			v1.push_back(node[p]);
		}else v2.push_back(node[p]);
		p = node[p].nex;
	}
	v.insert(v.end(), v1.begin(), v1.end());
	v.insert(v.end(), v2.begin(), v2.end());
	for(int i = 0; i < v.size(); i++){
		if(i != v.size() - 1){
			printf("%05d %d %05d\n", v[i].add, v[i].data, v[i+1].add);
		}else{
			printf("%05d %d -1\n", v[i].add, v[i].data);
		}
	}
	return 0;
} 
