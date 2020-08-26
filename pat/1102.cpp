/*
invert a binary tree  输出二叉树的层序遍历 和 中序遍历
invert 是反转的意思   左右孩子调换
建树的时候 把 反存左右孩子 即可达到 invert的目的
*/
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int right,left; //-1代表没有
}node[11];
int n,exist[11];
vector<int> in,level; 
void init(){
    memset(exist,0,sizeof(exist));
    in.clear();
    level.clear();
}
//反向建树
void buildTree(int n){
    char lchild,rchild;
    for(int i = 0; i < n; i++){
        cin >> lchild >> rchild;
        if(lchild == '-') node[i].right = -1;
        else {
            node[i].right = lchild - '0';
            exist[lchild-'0'] = 1;
        }
        if(rchild == '-') node[i].left = -1;
        else {
            node[i].left = rchild - '0';
            exist[rchild - '0'] = 1;
        }
    }
}
//中序遍历
void inOrder(int rt){
    if(rt == -1) return;
    inOrder(node[rt].left);
    in.push_back(rt);
    inOrder(node[rt].right);
}
//层序遍历
void levelOrder(int rt){
    queue<int> q;
    q.push(rt);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        level.push_back(u);
        if(node[u].left != -1) q.push(node[u].left);
        if(node[u].right != -1) q.push(node[u].right);
    }
}

int main(){
    init();
    int root;
    cin >> n;
    buildTree(n);
    
    //find root
    for(int i = 0; i < n; i++){
        if(!exist[i]){
            root = i;
            break;
        }
    }
    levelOrder(root);
    inOrder(root);
    //指针迭代法遍历
    vector<int>:: iterator it;
    for(it = level.begin(); it!=level.end(); it++){
        cout << (*it) ;
        if(it != level.end() - 1) cout <<" ";
    }
    cout << endl;
    // cout << level[0];
    // for(int i = 1; i < n; i++) 
    //     cout << " " << level[i];
    // cout << endl;
    //数组直接
    cout << in[0];
    for(int i = 1; i < n; i++)
        cout << " " << in[i];
    // cout << endl;
    return 0;
}
/*
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6

*/