#include <bits/stdc++.h>
#define Max 22
using namespace std;
struct Node{
	string data;
	int left, right;
}vec[Max];
//vector<Node> vec[Max];
int n, rt = 1;
string dfs(int index){
	if(index == -1) return "";
	if(vec[index].right != -1){
		vec[index].data = dfs(vec[index].left) + vec[index].data + dfs(vec[index].right);
		//非根节点 非叶子结点 
		if(index != rt){
			vec[index].data = '(' + vec[index].data + ')';
		}
	} 
	return vec[index].data;
}
int main(){
	vector<bool> vis(n+1, false);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> vec[i].data >> vec[i].left >> vec[i].right;
		if(vec[i].left != -1) vis[vec[i].left] = true;
		if(vec[i].right != -1) vis[vec[i].right] = true;
	}
	while(vis[rt] == true) rt ++;// 找根节点
	cout << dfs(rt) << endl; 
	return 0;
}
