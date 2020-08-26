#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	int end = n - 1;//字符串的最后一个字符
	int count = 0; //交换次数
	int oddNum = 0; //判断是否已经有一个单独的奇个数的字符了
	for(int i = 0; i < end; i++){
		for(int j = end; j >= i; j--){
			if(i == j){
				if(n % 2 == 0 || oddNum ==1){
					cout << "Impossible" << endl;
					return 0;
				}
				oddNum = 1;
				count += n/2 - i;   
			}else if(s[i] == s[j]){
				for(int k = j; k < end; k++){
					swap(s[k], s[k + 1]);
					count++;
				} 
				end--;
				break; //开始从i+1处重复操作 
			}
		}
	}
	cout << count << endl;
	return 0;
}
