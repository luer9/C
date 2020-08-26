#include <stdio.h>
struct Book
{
    char name[40];
    double price;
}book[20];

int n;

int main(){

    double maxx = -1, minn = 9999999; 
    int maxx_id = -1, minn_id = -1;
    scanf("%d",&n);
    getchar();
    for(int i = 0; i < n; i++) {
        gets(book[i].name);
        scanf("%lf",&book[i].price);
        getchar();
        if(book[i].price > maxx){
            maxx = book[i].price;
            maxx_id = i;
        }
        if(book[i].price < minn){
            minn = book[i].price;
            minn_id = i;
        }
    }
    printf("%.2lf, %s\n",book[maxx_id].price,book[maxx_id].name);
    printf("%.2lf, %s\n",book[minn_id].price,book[minn_id].name);
    return 0;
}