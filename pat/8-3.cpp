//n�����������  r�ǹ�ϵ k�Ƕ��������
// m �� ���䷽��
// ÿһ���������� ��i���±��� �����ڵ�i������
// yes ��û�����������������ڵĶ�������ͬ��
// no �Ǽƻ��и��������� ���� K �Ļ� ����� too many���� or too few ����
#include <bits/stdc++.h>
#define Max 505
using namespace std;
map<int, int> col;
set<int> spNum; // plan������ ����
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
					if(rela[i][j] && plan[i] == plan[j]) // �й�ϵ ��ɫ����ͬ
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
