//����  ����  --> ����
//����� Ψһ����� Yes �������No
//����������� 
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
	//����Ŀ�ʼ�ĵ�һ��Ӧ���Ǻ�������һ������ȵģ���������Ǹ����
	node *rt = new node();
	rt->data = pre[prel]; 
	rt->lchild = NULL;
	rt->rchild = NULL;
	if(prel == prer) return rt;
	//�����������ķ�Χ
	//�����������ҵ����������ڵ��λ��
	int i;
	//�Ժ���ĸ�����ǰ��һ�������Ϊ�ο���Ѱ���������������λ�ã��Ϳ��Ը������λ�����������Һ���
	for(i = prel; i <= prer; i++){
		if(post[postr - 1] == pre[i])
			break;
	} 
	if(i - prel > 1){
		//������:prel+1, i - 1   i-1-(prel + 1)+1 --> i-1-prel  
		rt->lchild = create(prel+1, i-1, postl, postl+i-prel-2); 
		//������ 
		rt->rchild = create(i, prer, postl+i-prel-1, postr-1);
	}else { // i == prel + 1 ���������ĸ��ڵ��غ��� 
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
