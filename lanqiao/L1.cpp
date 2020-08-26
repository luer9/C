#include <iostream>
#include <cstring>
using namespace std;
int n, ans[101][101];
int main(){
    memset(ans,0,sizeof(ans));
    cin >> n;
    ans[1][1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << ans[i][j];
            if(j != i) cout << " ";
        }
        cout << endl;
    }
    return 0;
}