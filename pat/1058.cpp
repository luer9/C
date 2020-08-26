#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    int aa, bb, cc;
    scanf("%d.%d.%d",&a, &b, &c);
    scanf("%d.%d.%d",&aa,&bb,&cc);
    c+=cc; b+=bb; a+=aa;
    b += c/29; c %= 29;
    a += b/17; b %= 17;
    printf("%d.%d.%d\n",a,b,c);
    return 0;
}