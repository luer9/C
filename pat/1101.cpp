/*
题目大致意思是：找一个数满足这个数小于其左边的所有数，大于其右边的所有数
最后升序输出，末尾不加空格
正整数 N <= 10^5

思路：
声明两个数组 Amin ，Amax
Amax[i] 代表 到第i个数为止其左边最大的数
Amin[i] 代表 到第i个数为止其右边最小的数
ans[i] 结果数组
*/
#include <bits/stdc++.h>
#define Max 100022
#define inf 0x3f3f3f3f
using namespace std;
int n;
int num[Max];
int Amax[Max],Amin[Max];
int ans[Max];
int ind;
void init(){
    ind = 0;
    memset(Amin,inf,sizeof(Amin));
    memset(Amax,-1,sizeof(Amax));
}
int main(){
    init();
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i]; 
    }
    for(int i = 1; i <= n; i++){
        // cout <<"***: "<< num[i] << "  " << Amax[i-1] << endl;
        if(num[i]>=Amax[i-1]){
            Amax[i] = num[i];
        }else {
            Amax[i] = Amax[i-1];
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << Amax[i]<<" -";
    // }
    // cout << endl;
    for(int i = n; i >=1 ; i--){
        // cout <<"***: "<< num[i] << "  " << Amin[i+1] << endl;
        if(num[i]<=Amin[i+1]){
            Amin[i] = num[i];
        }else {
            Amin[i] = Amin[i+1];
        }    
    }
    for(int i = 1; i <= n; i++){
        if(num[i] > Amax[i-1] && num[i] < Amin[i+1]){
            ans[ind++] = num[i];
        } 
    }

    sort(ans,ans+ind);
    cout << ind << endl;
    for(int i = 0 ; i < ind; i++) {
        cout << ans[i] ;
        if(i != ind-1){
            cout << " ";
        }else cout << endl;
    }
    if(ind == 0) cout << endl; //坑点！！！！！！！
    return 0;
}