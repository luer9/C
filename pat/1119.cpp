//先序  后序  --> 中序
//如果是 唯一的输出 Yes 不是输出No
//输出中序序列 
#include <bits/stdc++.h>
#define Max 33
using namespace std;
int pre[Max], post[Max], n;
struct node{
	int data;
	struct node *lchild, *rchild;
}; 
vector<int> ans;
int flag = 1;

node *create(int prel, int prer, int postl, int postr){
	if(prel > prer) return NULL;
	//先序的开始的第一个应该是后序的最后一个是相等的，这个结点就是根结点
	node *rt = new node();
	rt->data = pre[prel]; 
	rt->lchild = NULL;
	rt->rchild = NULL;
	if(prel == prer) return rt;
	//找左右子树的范围
	//在先序里面找到右子树根节点的位置
	int i;
	//以后序的根结点的前面一个结点作为参考，寻找这个结点在先序的位置，就可以根据这个位置来划分左右孩子
	for(i = prel; i <= prer; i++){
		if(post[postr - 1] == pre[i])
			break;
	} 
	if(i - prel > 1){
		//左子树:prel+1, i - 1   i-1-(prel + 1)+1 --> i-1-prel  
		rt->lchild = create(prel+1, i-1, postl, postl+i-prel-2); 
		//右子树 
		rt->rchild = create(i, prer, postl+i-prel-1, postr-1);
	}else { // i == prel + 1 左右子树的根节点重合了 
		flag = 0;
		rt->rchild = create(i, prer, postl+i-prel-1, postr-1); 
	}
	return rt;
}
void inorder(node *rt){
	if(!rt) return;
	inorder(rt->lchild);
	ans.push_back(rt->data);
	inorder(rt->rchild);
}
int main(){
	ans.clear();
	cin >> n;
	for(int i = 0; i < n; i++) cin >> pre[i];
	for(int j = 0; j < n; j++) cin >> post[j];
	node *rt = create(0, n-1, 0, n-1);
	inorder(rt);
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
		if(i != ans.size() - 1) cout << " "; 
	}
	cout << endl;
	return 0;
} 
