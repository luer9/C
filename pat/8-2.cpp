//������дһ�������ж���ҵ����־�������Ӯ��
//ÿ����Ҹ��������� ������֮ǰ�Ѿ����ڵ� npos
// n����ҵ�����  m�Ǳ����غ�
//�����i������ڵ�k�ֳ��־ʹ�ӡ Round���� i is out ������ʣ�¸������ֶ�������
//�������һ���������ͬ�Ļغ�out����ô�������ӡ���ǵ��±�
//���һ����Ҹ������� ������ ǰһ����� �� ֮ǰ��������������֮��Ĳ�ֵ
//�� out   ֮��Ĳ�������ȷ����Ĳ����
//��Ϸ������ ��ӡ������� ����

#include <bits/stdc++.h>
#define Max 100050
using namespace std;
set<int> allNum;//��������
int isIng[Max];//�ж�������Ƿ���Ա�����
set<int> cha; //��
int n, m;// ������� �� m�Ǳ����غ�
int roun[11][1003]; //��i���� �� j �ֵ�����
int a0, b0;//��ʼ��
void procha() {
	set<int> ::iterator it1,it2;
	for(it1 = allNum.begin(); it1 != allNum.end(); it1++) {
		for(it2 = allNum.begin(); it2 != allNum.end(); it2++) {
			cha.insert((*it1)-(*it2));
			cha.insert((*it2)-(*it1));
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	memset(isIng, 0, sizeof(isIng));
	cin >> a0 >> b0;
	allNum.insert(a0);
	allNum.insert(b0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> roun[i][j];
		}
	}
	//m��

	for(int j = 1; j <= m; j++) {
		set<int> out;//��¼ÿ�ֳ��ֵ���
		out.clear();
		//��
		for(int i = 1; i <= n; i++) {
			//�����i����û�б�����
			if(!isIng[i]) {
				procha();
				//�����Ҳ���  ����֮ǰ���ֹ�  out
//				cout << "***-�� " << cha.count(roun[i][j]) << " " << allNum.count(roun[i][j]) << endl;
				if(cha.count(roun[i][j]) == 0 || allNum.count(roun[i][j]) != 0) {
					out.insert(i);
					isIng[i] = 1;
				} else {
					allNum.insert(roun[i][j]);
				}
			}
		}
		set<int>::iterator ss;
		if(out.size() == 1) {

			cout << "Round #" << j << ": " << (*out.begin()) << " is out." << endl;
		} else if(out.size() > 1) {
			cout << "Round #" << j << ":";
			for(ss = out.begin(); ss != out.end(); ss++) {
				cout << " " << (*ss);

			}
//			cout << endl;
			cout << " is out." << endl;
		}
	}
	set<int> win;
	win.clear();
	for(int i = 1; i <= n; i++) {
		if(!isIng[i]) win.insert(i);
	}
	if(win.size() != 0) {
		cout << "Winner(s):";
	} else {
		cout << "No winner.";
	}
	set<int> ::iterator winner;
	for(winner = win.begin(); winner != win.end(); winner++) {
		cout << " " << (*winner);
	}
	return 0;
}
