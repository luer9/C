#include <bits/stdc++.h>
using namespace std;
int main() {
    char ans[13];
    for(int i = 0; i < 10; i++) ans[i] = i + '0';
    ans[10] = 'A',ans[11] = 'B',ans[12] = 'C';
    int a[3];
    for(int i = 0; i < 3; i++) cin >> a[i];
    cout << "#";
    for(int i = 0; i < 3; i++){
        cout << ans[a[i]/13] << ans[a[i]%13];
    }
    return 0;
}