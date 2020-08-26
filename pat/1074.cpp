#include <bits/stdc++.h>
#define Max 100005 
using namespace std;
struct Node{
	int addr, data, nex;
}node[Max];
int first, n, k; 
int main(){
	int a, b, c, ind = 0;
	scanf("%d%d%d", &first, &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &a, &b, &c);
		node[a].addr = a;
		node[a].data = b;
		node[a].nex = c;
	}
	vector<Node> vec;
	while(first != -1) {
		vec.push_back(node[first]);
		first = node[first].nex;
	} 
	while(ind + k <= vec.size()){
		reverse(vec.begin() + ind, vec.begin() + ind + k);
		ind += k;
	}
	printf("%05d %d ",vec[0].addr, vec[0].data);
	for(int i = 1; i < vec.size(); i++){  //nex就是下一个地址 
		printf("%05d\n%05d %d ",vec[i].addr, vec[i].addr, vec[i].data);
	}
	printf("-1\n");
	return 0;
}
