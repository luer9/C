#include <bits/stdc++.h>
#define Max 105
using namespace std;
int A[Max], B[Max], ans[Max];
string a, b;
int main(){
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    memset(ans, 0, sizeof(ans));
    cin >> a >> b;
    int lena = a.length(), lenb = b.length();
    for(int i = lena - 1; i >= 0; i--){
        A[lena - 1 - i] = a[i]-'0'; //A[0] 个位 
    }
    for(int j = lenb - 1; j >=0 ; j--){
        B[lenb - 1 - j] = b[j]-'0'; //B[0] 十位 
    }
//    for(int i = 0; i < lena; i++) {
//        cout << A[i];
//    }
//    cout << endl;
//    for(int i = 0; i < lenb ; i++){
//        cout << B[i];
//    }
//    cout << endl;
    int i, j, z = 0;
    int c = 0;
    int s;
    for(i = 0, j = 0; i < lena && j < lenb; i++, j++){
        s = A[i] + B[j] + c;
        ans[z++] = s % 10;
        c = s / 10;
    }
    if(i == lena) {
        for(int k = lena; k < lenb; k++){
            s = B[k] + c;
            ans[z++] = s % 10;
            c = s / 10; 
        }
    }
    if(j == lenb){
        for(int k = lenb; k < lena; k++){
            s = A[k] + c;
            ans[z++] = s % 10;
            c = s / 10;
        }
    }
    if(c!=0){
    		ans[z++] = c;
	}
    // int pos = 0;
    // for(int k = z; k <= 0; k--){
    //     if(ans[k] != 0) {
    //         pos = k;
    //         break;
    //     }
    // }
//    cout << z << endl;
    for(int k = z - 1; k >= 0; k--){
        cout << ans[k];
    }
    cout << endl;
    return 0;
}
