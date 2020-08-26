
#include<stdio.h>
#include<string.h>
void f(int n);
int main(){
	int n;
	scanf("%d",&n);
	f(n);
	return 0;
}
void f(int n){
	if(n==1){
		printf("A");
	}
	else {
		f(n-1);
		printf("%c",'A'+n-1);
		f(n-1);
	}
}


