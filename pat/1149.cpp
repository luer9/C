#include <bits/stdc++.h>
#define Max 99999
using namespace std;
vector<int> vec[Max];
int n, m, k;
int u, v;
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u); //ª•≤ªœ‡»› 
	}
	int goods[Max];
	vector<int> temp;	
	while(m--) {
		memset(goods, 0, sizeof(goods));	
		temp.clear();
		cin >> k;
		for(int i = 0; i < k; i++){
			cin >> goods[i];
			temp.insert(temp.end(), vec[goods[i]].begin(), vec[goods[i]].end());
//			cout <<"----> "<< temp.size() << endl;
		}
		int flag = 0;
		vector<int>::iterator it;
		for(int i = 0; i < k; i++){
			it = find(temp.begin(), temp.end(), goods[i]);
			if(it != temp.end()){
				flag = 1;
				break;
			}
		} 
		if(flag) cout << "No" << endl;
		else cout << "Yes" << endl; 
	}
	return 0;
} 
