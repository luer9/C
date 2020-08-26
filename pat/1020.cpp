#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

int n;
int postorder[30];
int inorder[30];
int visited[30] = {false};

void createTree(node *root, int r) {
	int rindex;
	for(int i=0; i<n; i++)
		if(inorder[i] == postorder[r]) {
			rindex = i;
			break;
		}
	visited[rindex] = true;
	int lcn = 0, rcn = 0;
	for(int i=rindex-1; !visited[i]&&i>=0; i--) //左子树个数 
		lcn++;
	for(int i=rindex+1; !visited[i]&&i<n; i++)  //右子树个数 
		rcn++;
	if(lcn == 0)
		root->left = NULL;
	else { //左子树不为空 
		node *lc = new node;
		lc->data = postorder[r-rcn-1];
		root->left = lc;
		createTree(lc, r-rcn-1);
	}
	if(rcn == 0)
		root->right = NULL;
	else { //右子树不为空 
		node *rc = new node;
		rc->data  =postorder[r-1];
		root->right = rc;
		createTree(rc, r-1);
	}
}
void level(node root) {
	queue<node> que;
	que.push(root);
	while(!que.empty()) {
		node tmp = que.front();
		que.pop();
		cout<<tmp.data;
		if(tmp.left != NULL)
			que.push(*tmp.left);
		if(tmp.right != NULL)
			que.push(*tmp.right);
		if(!que.empty())
			cout<<" ";
	}
}
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &postorder[i]);
	for(int i=0; i<n; i++)
		scanf("%d", &inorder[i]);
	node root;
	root.data = postorder[n-1];
	createTree(&root, n-1);
	level(root);
	return 0;
}

//https://blog.csdn.net/qq_40941722/article/details/104005465 
