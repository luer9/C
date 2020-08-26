#include <bits/stdc++.h>
using namespace std;
int main(){

    char mapp[30][30];
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        mapp[0][i] = 'A'+i;
        // cout << mapp[0][i]; 
    }
    for(int i = 1; i < n; i++){
        // cout << "*******" << endl;
        for(int j = 0; j < m; j++){
            if(j == 0) mapp[i][j] = 'A' + i;
            else {
                mapp[i][j] = mapp[i-1][j-1];
                // cout << "what "<<endl;
            }
            // cout << mapp[i][j];
        }
    }
    // cout << n << " " << m << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // cout << "***"<< endl;
            cout << mapp[i][j];
        }
        cout << endl;
    }
    return 0;
}