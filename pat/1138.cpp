#include <bits/stdc++.h>
#define Max 50005
using namespace std;
int pre[Max], in[Max], n;
int flag;
void postTravel(int now, int l, int r){
	if( l > r || flag == 1) {
		return ;
	}
	int i = l;
	while( in[i] != pre[now] ) i++;
	postTravel(now+1, l, i-1);
	postTravel(now+1+i-l, i+1, r);
	if(!flag){
		cout << pre[now];
		flag = 1;
	}
}
int main(){
	flag = 0;
	memset(pre, 0, sizeof(pre));
	memset(in, 0, sizeof(in));
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> pre[i];
	}
	for(int i = 0; i < n; i++){
		cin >> in[i];
	}
	postTravel(0, 0, n-1);
	return 0;
} 
//后序遍历的最后一个元素是整个二叉树的根节点
/*

不用建树
首先，先序遍历第一个一定是根节点。现在暂时叫它NOW（在先序遍历里的位置）（即当前节点）
然后在中序遍历里找到NOW的位置，假设位置下标是POS（中序遍历），那么左边的就是左子树（L ~ POS-1），右边的就是右子树（POS+1 ~ R）。(都是指中序遍历)
一开始的范围是0~N-1（L ~ R)
遍历左子树：
根节点下标是NOW+1（先序遍历），左边界依然是 L , 右边界是POS - 1.
遍历右子树：
根节点：NOW+1+（POS-L） 左边界：POS+1 右边界：R

然后递归遍历就可以了，这里只要输出后序遍历的第一个节点，所以输出完直接return了

*/
