#include <iostream>
#include <cstring>
#include <map>
#include <string>
using namespace std;
string s;
map<char,int> mapp;
int check(string s) {
	int len = s.length();
	//��һ����ĸ���Ǹ���||���һ����ĸ����Ԫ��
	if(mapp[s[0]] != 0 || mapp[s[len - 1]] != 1) {
		return 0;
	}
	int cnt_yuan = 0, cnt_fu = 0; //��¼ ��ͷԪ�� ���� ���ֵĴ���
	for(int i = 0; i < len;) {
		//�Ǹ���
		if(mapp[s[i]] == 0) {
//			cout << "* --------->fu:  " << s[i] << endl; 
			cnt_fu++;
			for(int j = i+1; j < len; j++) {
				//���һֱ�Ǹ�����һֱ��
				if(mapp[s[j]] == 0) {
					i++;
					if(i >= len) break;
				} else { //�����˳�����������
					i = j;
//					cout << "i:::������Ҫ�������±� " << i << endl;
					break;
				}
			}
		} else if(mapp[s[i]] == 1) {
//			cout << "* --- >yuan: " << s[i] << endl;
			cnt_yuan++;
			for(int j = i + 1; j < len; j++){
				//���һֱ��Ԫ��
				if(mapp[s[j]] == 1){
					i++;
					if(i >= len) break;
				} else{ // ������Ǹ��� 
					i = j;
//					cout << "i:::::������Ҫ�������±� " << i << endl;
					break; 
				}
			}
		}
		if(i == len - 1) break;
	}
//	cout <<"----> fu::"<< cnt_fu << "  " << "------> yuan::" <<cnt_yuan << endl;
	if(cnt_fu == 2 && cnt_yuan == 2){
		return 1;
	} else return 0;
}
int main() {
	mapp.clear();
	mapp['a'] = 1;
	mapp['e'] = 1;
	mapp['i'] = 1;
	mapp['o'] = 1;
	mapp['u'] = 1;
	cin >> s;
	if(check(s)) {
		cout << "yes" << endl;
	} else cout << "no" << endl;
	return 0;
}
