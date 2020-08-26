#include <bits/stdc++.h>
#define Max 100005
using namespace std;
int maxlevel=0,num=0;
struct Node {
	int sum;
	vector<int> child;
} node[Max];
double ans;
int n, k, v;
double p, r;
void dfs(int index,int level) {
	if(node[index].child.size()==0) { //�ҵ�Ҷ�ڵ�
		ans+=node[index].sum*pow(1+r, level);//������������������������Ӵ���۸�����
		return;
	}
	for(int i=0; i<node[index].child.size(); i++) //�ݹ�ķ���ÿһ���ӽڵ�
		dfs(node[index].child[i], level+1);
}
int main() {
	cin >> n >> p >> r;
	r = r / 100.0;
	for(int i = 0; i < n; i++) {
		cin >> k;
		if(k == 0) {
			cin >> node[i].sum;
		} else {
			for(int j = 0; j < k; j++) {
				cin >> v;
				node[i].child.push_back(v);
			}
		}
	}
	dfs(0,0);
	cout << fixed << setprecision(1) << p * ans << endl;

	return 0;
}

