#include <bits/stdc++.h>
using namespace std;
void Hanoi(int n, char a, char b, char c){
	if(n == 1) { // �ݹ���� 
		cout << "���� " << n << " ����Ƭ�� " << a << " �ƶ��� " << c << endl;
		return ; 
	}else{
		Hanoi(n-1, a, c, b); // ��n-1��Բ�̴� a ���� c �ƶ� �� b 
		cout << "���� " << n <<" ����Ƭ�� " << a << " �ƶ��� " << c << endl; 
		Hanoi(n-1, b, a, c); //��n-1��Բ�̴� b ���� a �ƶ��� c 
	}
}
int main(){
	int n; // ��ŵ�����ӵ���Ŀ
	cout << "�����뺺ŵ�����ӵ���Ŀ��" << endl;
	cin >> n;
	cout << n << " ����Ƭ�ƶ����̣�" << endl; 
	Hanoi(n,'A','B','C'); 
	return 0;
}
