#include <bits/stdc++.h>
#define Max 10024 
using namespace std;
vector<int> vec[Max]; //�� i ������� �� 
int vis[Max]; //����
int n, m, q, nv;
int u, v; 
int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		vec[u].push_back(i);
		vec[v].push_back(i); 
	} 
	cin >> q;
	while(q --) {
		memset(vis, 0, sizeof(vis));
		cin >> nv;
		for(int i = 0; i < nv; i++){
			cin >> u;
			for(int j = 0; j < vec[u].size(); j++){
				vis[vec[u][j]] = 1;
			}
		}
		int flag = 0;
		for(int i = 0; i < m; i++){
			if(vis[i] != 1) {
				flag = 1;
//				cout << "No" << endl;
				break;
			}
		}
		if(flag) cout << "No" << endl;
		else cout << "Yes" << endl;
	} 
	return 0;
}
//��ÿ����������ıߴ洢���� �ߵı�� �� 1 ��ʼ 
