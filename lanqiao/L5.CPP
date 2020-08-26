#include <bits/stdc++.h>
#define Max 3001
using namespace std;
int main(){
    int A[Max], n;
    int s;//记录每次乘阶乘之后的数据
    int c = 0;//进位
    memset(A, 0, sizeof(A));
    cin >> n;
    A[0] = 1;
    //将数组A的每一个元素都乘以k，请注意处理相应的进位。
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < Max; j++){
            s = A[j] * i + c;
            c = s / 10;
            A[j] = s % 10;
        }
    }
    int pos = 0;
    for(int i = Max; i >= 0; i--){
        if(A[i]!=0) {
            pos = i;
            break;
        }
    }
    for(int i = pos; i >= 0; i--) {
        cout << A[i];
    }
    cout << endl;
    return 0;
}