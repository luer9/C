#include <bits/stdc++.h>
using namespace std;
string s;
int findE(string s) {
	int len = s.length();
	for(int i = 0; i < len; i++) {
		if(s[i] == 'E') {
			return i;
		}
	}
}
int main() {
	int flag1 = 0, len, len_temp, move = 0, pos;
	string temp = "", num = "";
	cin >> s;
	len = s.length();
	pos = findE(s);
	num = s.substr(0, pos); 
	temp = s.substr(pos + 1, len - pos - 1);
	len_temp = temp.length();
//	cout << "****: " << num << endl;
	if(temp[0] == '-') {
		flag1 = 0; // �����ƶ�
	} else flag1 = 1; //�����ƶ�
	 
	for(int i = 1; i < len_temp; i++) {
		move = move * 10 + (temp[i] - '0'); 
	}
	if(s[0] == '-'){
		if(flag1) { // ���� 
			int len1 = num.length() - 2; //��ȥ���� �� .
			int len2 = len1 - 1; //��ȥ��һλ 
			int add0 = move - len2;
//			cout << "len1: " << len1 << " len2 : " << len2 << " add0: " << add0 << endl;
			if(add0 > len2){ //��Ҫ��0����� 
				for(int i = 0; i < num.length(); i++){
					if(num[i] == '.') continue;
					cout << num[i];
				}
				for(int i = 0; i < add0; i++){
					cout << "0";
				}
			}else { //����Ҫ�������� 
				int i = 0, j = 0;
				for(i = 0; i < num.length(); i++){
					if(num[i] == '.') break;
					cout << num[i];
				}
				for(j = i + 1; j < move + i + 1; j++){
					cout << num[j];
				}
				for(i = j; i < num.length(); i++) {
					if(i == j) cout << ".";
					cout << num[i];
				}
			}
		}else{//���� 
			cout << num[0];
			for(int i = 0; i < move; i ++){
				if(i == 0) cout << "0.";
				else cout << "0";
			}
			for(int i = 0 ; i < num.length(); i++){
				if(num[i] == '.') continue;
				cout << num[i];
			}
		}
	}else if(s[0] == '+'){
		//����
		if(flag1) {
			int len1 = num.length() - 2; //��ȥ���� �� .
			int len2 = len1 - 1; //��ȥ��һλ 
			int add0 = move - len2;
//			cout << "len1: " << len1 << " len2 : " << len2 << " add0: " << add0 << endl;
			if(add0 > len2){ //��Ҫ��0����� 
				for(int i = 1; i < num.length(); i++){
					if(num[i] == '.') continue;
					cout << num[i];
				}
				for(int i = 0; i < add0; i++){
					cout << "0";
				}
			}else { //����Ҫ�������� 
				int i = 0, j = 0;
				for(i = 1; i < num.length(); i++){
					if(num[i] == '.') break;
					cout << num[i];
				}
				for(j = i + 1; j < move + i + 1; j++){
					cout << num[j];
				}
				cout << ".";
				for(i = j; i < num.length(); i++) {
					cout << num[i];
				}
			}
		} else{	//���� 
			for(int i = 0; i < move; i ++){
				if(i == 0) cout << "0.";
				else cout << "0";
			}
			for(int i = 1; i < num.length(); i++){
				if(num[i] == '.') continue;
				cout << num[i];
			}
		}
	
	}
	return 0;
}
