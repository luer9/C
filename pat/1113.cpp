//�������ϵ�Ԫ�ظ�������С������£���֤�������ϵĲ����
//|n1-n2| ��С����� 0,1 
#include <bits/stdc++.h>
#define Max 100015
using namespace std;
int a[Max], n; 
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < n/2; i++){
		sum1 += a[i];
	}
	for(int i = n/2; i < n; i++){
		sum2 += a[i];
	}
	if(n%2 == 1){
		cout << 1 << " " << sum2 - sum1 << endl;
	}else cout << 0 << " " << sum2 - sum1 << endl;
	return 0;
}
