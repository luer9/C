#include <bits/stdc++.h>
#define Max 100000
using namespace std;
struct Node {
	int address, key, nex;
} node[Max],node1[Max];
int n, st, ad;
int vis[Max];
int cmp(Node a, Node b) {
	return a.key < b.key;
}
int main() {
	memset(vis, 0, sizeof(vis));
	cin >> n >> st;
	for(int i = 0; i < n; i++) {
		scanf("%d",&ad);
		scanf("%d%d",&node[i].key, &node[i].nex);
		node[i].address = ad;
		node1[ad] = node[i];
	}
	int cnt = 0;
	vis[node1[st].address] = 1;
	while(st != -1) {
		cnt++;
		st = node1[st].nex;
		vis[node1[st].address] = 1;
	}
//	cout << cnt << endl;
	if(cnt != 0) {
		sort(node, node + n, cmp);
		int i = 0;
		while(!vis[node[i].address]) {
			i++;
		}
		if(i!=n)
			printf("%d %05d\n%05d %d ", cnt, node[i].address, node[i].address, node[i].key);
		i++;
		for(; i < n; i++) {
			if(vis[node[i].address])
				printf("%05d\n%05d %d ", node[i].address, node[i].address, node[i].key);
		}
		printf("-1\n");
	}
	else printf("0 -1\n"); ///最后一个测试点 
	return 0;
}
