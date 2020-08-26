#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left, *right;
};
int n, x;
struct node *root = NULL;
vector<int> pre, post, vec;
void Insert(node * &root,int data)
{
	if(root == NULL)
	{
		root = new node();
		root->data = x;
		root->left = root ->right =NULL;		
	}else if(data < root->data)
		Insert(root->left,data);
	else if(data >= root->data)
		Insert(root->right,data);
 
}
void preorder1(node * root)
{
	if(root)
	{
		pre.push_back(root->data);
		preorder1(root->left);
		preorder1(root->right);
	}	
}
void preorder2(node * root)
{
	if(root)
	{
		pre.push_back(root->data);
		preorder2(root->right);
		preorder2(root->left);
	}	
}
void postorder1(node * root)
{
	if(root)
	{
		postorder1(root->left);
		postorder1(root->right);
		post.push_back(root->data);
	}	
}
void postorder2(node * root)
{
	if(root)
	{
		postorder2(root->right);
		postorder2(root->left);
		post.push_back(root->data);
	}	
}
int main(){
	cin >> n; 
	for(int i = 1; i <= n; i++){
		cin >> x;
		vec.push_back(x);
		Insert(root, x);
	} 
	pre.clear();
	preorder1(root);
	int i;
	for(i = 0; i < n; i++){
		if(vec[i] != pre[i]){
			break;
		}
	}
	if(i == n){
		cout << "YES" << endl;
		postorder1(root);
		for(int j = 0; j < n; j++){
			cout << post[j];
			if(j != n-1) cout << " ";
		} 
		return 0;
	}
	pre.clear();
	preorder2(root);
	for(i = 0; i < n; i++){
		if(vec[i] != pre[i]){
			break;
		}
	}
	if(i == n){
		cout << "YES" << endl;
		postorder2(root);
		for(int j = 0; j < n; j++){
			cout << post[j];
			if(j != n-1) cout << " ";
		}
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}
