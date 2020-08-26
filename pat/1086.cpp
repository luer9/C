//根据 中序 前序  找 后序 
#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in, post;
int n, num;
string opt;
//rt是前序当前根节点的下标
//st，en 分别是当前子树在中序序列最左端和最右端的下标 
void postOrder(int rt, int st, int en){
	if(st > en) return ;
	int i = st;
	while(i < en && in[i] != pre[rt]) i++;
	postOrder(rt + 1, st, i - 1);
	postOrder(rt + 1 + i - st, i + 1, en);
	post.push_back(pre[rt]);
}
int main(){
	stack<int> s; 
	while(!s.empty()) s.pop();
	cin >> n;
	for(int i = 0; i < 2*n; i++){
		cin >> opt;
		if(opt == "Push"){ //前序 
			cin >> num;
			s.push(num);
			pre.push_back(num);
		}else{ //中序 
			in.push_back(s.top());
			s.pop();
		} 
	}
	postOrder(0, 0, n-1);
	for(int i = 0; i < n; i++){
		cout << post[i] ;
		if( i != n-1) cout << " ";
	}
	cout << endl;
	return 0;
}
