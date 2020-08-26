#include <bits/stdc++.h>
#define maxn 10050
using namespace std;
int a, b;
bool isprime[maxn+5];
int prime[maxn+5];
void getPrime()
{
    
    int index = 0;
    memset(isprime,true,sizeof(isprime));
    for(int i=2; i<=maxn; i++)
    {
        if(isprime[i])
            prime[index++] = i;
        for(int j=0; j < index && prime[j]*i <= maxn; j++)
        {
            isprime[prime[j]*i] = false;
            if(i%prime[j] == 0) //保证每个合数只会被它的最小质因数筛去，因此每个数只会被标记一次
                break;
        }
    }
}
int main(){
	cin >> a >> b;
	getPrime();
	for(int i = a; i <= b; i++){
		if(isprime[i]){
			cout << i << "=" << i << endl;
		}else{
			cout << i << "=";
			int index = 0;
			int temp = i;
			while(true){
				if(temp % prime[index] == 0) {
					cout << prime[index];
					temp /= prime[index];
					if(temp == 1){
						cout << endl;
						break;
					}else cout << "*";
					index = 0;
				}else{
					index ++;
				}
//				if(temp != 1){
//					cout << "*";
//				}else {
//					cout << endl;
//					break;
//				}
			}
		
		}
	}
	return 0;
}
