//n是区域的数量  r是关系 k是动物的种类
// m 是 分配方案
// 每一个方案给出 第i个下标是 动物在第i个区域
// yes 是没有在两个相邻区域内的动物是相同的
// no 是计划中给的种类数 不是 K 的话 就输出 too many…… or too few ……
#include <bits/stdc++.h>
#define Max 505
using namespace std;
map<int, int> col;
set<int> spNum; // plan给出的 种类
int rela[Max][Max], plan[Max];
int n, r, k, m, u, v;
int main() {
	memset(rela, 0, sizeof(rela));
	cin >> n >> r >> k;
	for(int i = 0; i < r; i++) {
		cin >> u >> v;
		rela[u][v] = rela[v][u] = 1;
	}

	cin >> m;
	for(int j = 0; j < m; j++) {
		spNum.clear();
		for(int i = 1; i <= n; i++) {
			cin >> plan[i];
			spNum.insert(plan[i]);
		}
		if(spNum.size() > k) {
			cout << "Error: Too many species." << endl;
		} else if(spNum.size() < k) {
			cout << "Error: Too few species." << endl;
		}else {
			int flag = 0;
			for(int i = 1; i <= n; i++){
				for(int j = i + 1; j <= n; j++){
					if(rela[i][j] && plan[i] == plan[j]) // 有关系 颜色还相同
					{
						flag = 1;
					 } 
				}
				if(flag) break;
			}
			if(flag) {
				cout << "No" << endl;
			}else cout << "Yes" << endl;
		} 

	}

	return 0;
}
