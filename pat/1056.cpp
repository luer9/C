#include <bits/stdc++.h>
using namespace std;
struct node{
	int weight, ind0, ind1, rank;
};
bool cmp(node a, node b){
	return a.ind0 < b.ind0;
}

int main(){
	int n, g, num;
	scanf("%d%d", &n, &g);
	vector<int> v(n);
	vector<node> w(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		w[i].weight = v[num];
		w[i].ind1 = i;
		w[i].ind0 = num;
	}
	queue<node> q;
	for(int i = 0; i < n; i++){
		q.push(w[i]);
	}
	while(!q.empty()){
		int size = q.size();
		if(size == 1){
			node temp = q.front();
			w[temp.ind1].rank = 1;
			break;
		}
		int group = size / g;
		if(size % g != 0){
			group++;
		}
		node maxnode;
		int cnt = 0, max = -1;
		for(int i = 0; i < size; i++){
			node temp = q.front();
			w[temp.ind1].rank = group + 1;
			q.pop();
			cnt++;
			if(temp.weight > max){
				maxnode = temp;
				max = temp.weight;
			}
			if(cnt == g || i == size - 1){
				cnt = 0;
				max = -1;
				q.push(maxnode);
			}
		}
	}
	sort(w.begin(), w.end(), cmp);
	for(int i = 0; i < n; i++){
		if(i != 0) printf(" ");
		printf("%d", w[i].rank);
	}
	return 0;
}
