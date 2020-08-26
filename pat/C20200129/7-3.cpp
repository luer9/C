#include <stdio.h>
int main(){
    int hh,mm,ss,n;
    scanf("%d:%d:%d",&hh,&mm,&ss);
    scanf("%d",&n);
    int total = hh*3600 + mm*60 + ss;
    total = total + n;
    hh = total / 3600;
    mm = total % 3600 / 60;
    ss = total % 3600 % 60;
    if(hh == 24) hh = 0;
    printf("%02d:%02d:%02d",hh,mm,ss);
    return 0;
}