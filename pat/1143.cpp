//#include <bits/stdc++.h>
//#define Max 10005
//using namespace std;
//struct node{
//	int val;
//	struct node *lchild, *rchild;
//};
//int m, n;
//map<int, int> vis;
//vector<int> preval(Max), inval(Max); //前序 中序 
//void createTree(node* &rt,vector<int> &pre,vector<int> in,int pl, int pr, int il, int ir){
//	if(il > ir || pl > pr) return ;
//	rt = new node();
//	rt->val = pre[pl]; 
//	rt->lchild = NULL; rt->rchild = NULL;
//	int temp = pre[pl];
//	int pos = il;
//	while(pos <= ir && in[pos] != temp){
//		pos++;
//	}
//	createTree(rt->lchild, pre, in, pl+1, pl+pos-il, il, pos - 1);//左子树 
//	createTree(rt->rchild, pre, in, pl+pos-il+1, pr, pos+1, ir);//右子树 
//	
//}
//void find(node *rt, int u, int v, bool flag){
//	if(rt == NULL) return;
//	if(rt->val == u){
//		cout << u <<" is an ancestor of " << v << "." << endl;
//		return;
//	} 
//	else if(rt->val == v){
//		cout << v <<" is an ancestor of " << u << "." << endl;
//		return ;
//	}else if( u > rt->val && v < rt->val){
//		if(flag){
//			cout << "LCA of " << u << " and " << v << " is " << rt->val <<"."<< endl; 
//		}else{
//			cout << "LCA of " << v << " and " << u << " is " << rt->val <<"."<< endl;
//		}
//		return;
//	}else if( u > rt->val && v > rt->val) 
//		find(rt->rchild, u, v, flag);
//	else find(rt->lchild, u, v, flag);
//} 
//int main(){
//	ios::sync_with_stdio(false);
//	cin >> m >> n;
//	vis.clear();
//	for(int i = 0; i < n; i++){
//		cin >> preval[i];
//		vis[preval[i]] = 1;
//	}
//	inval = preval;
//	sort(inval.begin(), inval.end());
//	node *rt = NULL;
//	createTree(rt, preval, inval, 0, n-1, 0, n-1); 
//	int u, v;
//	for(int i = 0; i < m; i++){
//		cin >> u >> v;
//		if(!vis[u] && !vis[v]){
//			cout << "ERROR: " << u << " and " << v <<" are not found." << endl;
//		}else if(!vis[u] && vis[v]){
//			cout << "ERROR: " << u << " is not found." << endl; 
//		}else if(vis[u] && !vis[v]){
//			cout << "ERROR: " << v << " is not found." << endl;
//		}else {
//			bool flag = true;
//			if(u <= v){
//				flag = false;
//				swap(u, v);
//			}
//			find(rt, u, v, flag);
//		}
//	}
//	return 0;
//} 


#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, ans, an[100005];
map<int,int> mp;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> an[i];
        mp[an[i]] = 1;
    }
    for(int i = 0 ; i < n; i++){
        cin >> x >> y;
        for(int j = 1; j<= m; j++){
            ans = an[j];
            if((ans >= x&&ans <= y)||(ans>=y && ans <= x))
                break;
        }
        if(mp[x] == 0 && mp[y] == 0)
            printf("ERROR: %d and %d are not found.\n", x,y);
        else if(mp[x] == 0)
            printf("ERROR: %d is not found.\n", x);
        else if(mp[y] == 0)
            printf("ERROR: %d is not found.\n", y);
        else if(ans==x || ans==y)
            printf("%d is an ancestor of %d.\n", ans==x?x:y,ans==x?y:x);
        else
            printf("LCA of %d and %d is %d.\n", x,y,ans);
    }
    return 0;
}
