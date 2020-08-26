//内存超限！！！！！ 
//#include <bits/stdc++.h>
//#define Max 10002
//using namespace std;
//int n, m;
//int u, v;
//int mapp[Max][Max];
//int k;
//int main() {
//	ios::sync_with_stdio(false);
//	memset(mapp, 0, sizeof(mapp));
//	cin >> n >> m;  // v --- 0 ~ n-1
//	for(int i = 0; i < m; i++) {
//		cin >> u >> v;
//		mapp[u][v] = mapp[v][u] = 1;
//	}
//
//	cin >> k;
//	while(k--) {
//		int col[Max], flag = 0;
//		memset(col, 0, sizeof(col));
//		vector<int> vec[Max];
//		set<int> s;
//		s.clear();
//
//		for(int i = 0; i < n; i++) {
//			cin >> col[i];
//			if(s.count(col[i])) { // 说明之前已经有点染过这个颜色
//				for(int j = 0; j < vec[col[i]].size(); j++) {
//					if(mapp[i][vec[col[i]][j]] == 1) {
//						flag = 1;
//						break;
//					}
//				}
//			} else {
//				s.insert(col[i]);
//			}
//			vec[col[i]].push_back(i);
//		}
//		if(flag) {
//			cout << "No" << endl;
//		} else {
//			cout << s.size() << "-coloring" << endl;
//		}
//	}
//
//	return 0;
//}
#include <bits/stdc++.h>
#define Max 10002
using namespace std;
struct Node{
	int u, v;
};
int n, m, k;
int main(){
	cin >> n >> m;
	vector<Node > vec(m);
	for(int i = 0; i < m; i++){
		cin >> vec[i].u >> vec[i].v;
	}	
	cin >> k;
	while(k --){
		int a[Max] = {0}, flag = 1;
		set<int> s; s.clear();
		for(int i = 0; i < n; i++){
			cin >> a[i];
			s.insert(a[i]);
		}
		for(int i = 0; i < m; i++){
			if(a[vec[i].u] == a[vec[i].v]){
				flag = 0;
				break;
			}
		} 
		if(flag){
			cout << s.size() << "-coloring" << endl;
		}else {
			cout << "No" << endl;
		}
	}
	return 0;
} 








