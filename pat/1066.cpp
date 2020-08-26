//AVL:平衡二叉搜索树
//AVL的代码模板 
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	struct Node *left, *right;
};  
//左旋
/*
  .
   .
    .
*/ 
Node *leftRotate(Node *rt){
	Node *temp = rt->right;
	rt->right = temp->left;
	temp->left = rt;
	return temp;
} 
//右旋
/*
	.
   .
  .	
*/ 
Node *rightRotate(Node *rt){
	Node *temp = rt->left;
	rt->left = temp->right;
	temp->right = rt;
	return temp;
} 
//先左再右旋
/*
	.                 .    
   .  <- 左旋   -->  .
    .	            .  
*/ 
Node *leftRightRotate(Node *rt){
	rt->left = leftRotate(rt->left);
	return rightRotate(rt); 
}
//先右再左旋
/*
	.                .
	 . <- 右旋  -->   .
	.                  .
*/
Node *rightLeftRotate(Node *rt){
	rt->right = rightRotate(rt->right);
	return leftRotate(rt); 
}
//高度
int getHg(Node *rt){
	if( rt == NULL) return 0;
	return max(getHg(rt->left), getHg(rt->right)) + 1;
} 
//插入 构造AVL
Node *insert(Node *rt, int val){
	if(rt == NULL){
		rt = new Node();
		rt->val = val;
		rt->right = rt->left = NULL; 
	}else if(val < rt->val ){
		rt->left = insert(rt->left, val);
		if(getHg(rt->left) - getHg(rt->right) == 2){
			rt = val < rt->left->val ? rightRotate(rt) : leftRightRotate(rt);
		}
	}else {
		rt->right = insert(rt->right, val);
		if(getHg(rt->left) - getHg(rt->right) == -2){
			rt = val > rt->right->val ? leftRotate(rt) : rightLeftRotate(rt);
		}
	}
	return rt;
}
int main(){
	int n, v;
	cin >> n;
	Node *rt = NULL;
	for(int i = 0; i < n; i++){
		cin >> v;
		rt = insert(rt, v);
	} 
	cout << rt->val << endl;
	return 0;
}
