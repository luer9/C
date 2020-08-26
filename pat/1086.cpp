//���� ���� ǰ��  �� ���� 
#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in, post;
int n, num;
string opt;
//rt��ǰ��ǰ���ڵ���±�
//st��en �ֱ��ǵ�ǰ������������������˺����Ҷ˵��±� 
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
		if(opt == "Push"){ //ǰ�� 
			cin >> num;
			s.push(num);
			pre.push_back(num);
		}else{ //���� 
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
