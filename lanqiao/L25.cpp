#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	int end = n - 1;//�ַ��������һ���ַ�
	int count = 0; //��������
	int oddNum = 0; //�ж��Ƿ��Ѿ���һ����������������ַ���
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
				break; //��ʼ��i+1���ظ����� 
			}
		}
	}
	cout << count << endl;
	return 0;
}
