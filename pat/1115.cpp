//先把树建起来 
#include <bits/stdc++.h>
#define Max 1111
using namespace std;
struct Node{
	int data;
	struct Node *lchild, *rchild;
};
int n, d;
int sum[Max];
int maxl;
void create(Node *&rt, int data){
	if(rt == NULL){
		rt = (Node*)malloc(sizeof(Node));
		rt->data = data;
		rt->lchild = rt->rchild = NULL;
		return; 
	}
	if(data <= rt->data){
		create(rt->lchild, data);
	}else if(data > rt->data){
		create(rt->rchild, data);
	}
}
void dfs(Node *rt, int l){
	if(l > maxl){
		maxl = l;
	}
	sum[l]++; 
	if(rt->lchild) dfs(rt->lchild, l+1);
	if(rt->rchild) dfs(rt->rchild, l+1);
}
int main(){
	cin >> n;
	Node *rt = NULL;
	for(int i = 0; i < n; i++){
		cin >> d;
		create(rt, d);
	}
	maxl = -1;
	memset(sum, 0, sizeof(sum));
	dfs(rt, 1);
//	cout << maxl << endl;
	cout << sum[maxl] << " + " << sum[maxl - 1] << " = " << sum[maxl] + sum[maxl - 1] << endl; 
	return 0;
}
