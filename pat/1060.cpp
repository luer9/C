//#include <bits/stdc++.h>
//using namespace std;
//int n, lena, lenb;
//string a, b;
//int getPos(string s){
//	int ind, len = s.length();
//	for(ind = 0; ind < len; ind++){
//		if(s[ind] == '.'){
//			return ind;
//		}
//	}
//	return ind;
//}
//int main(){
//	cin >> n >> a >> b;
//	lena = a.length();
//	lenb = b.length();
//	int slen1 = getPos(a), slen2 = getPos(b);
////	cout << slen1 << " " << slen2 << endl;
//	int flag = 0;
//	for(int i = 0; i < n; i++){
//		if(a[i] != b[i]){
//			flag = 1;
//			break;			
//		}
//	}
//	if(flag || slen1 != slen2){
//		cout << "NO ";
//		cout << "0." << a.substr(0, n) << "*10^" << slen1 << " ";
//		cout << "0." << b.substr(0, n) << "*10^" << slen2; 
//	}else{
//		cout << "YES ";
//		cout << "0." << a.substr(0, n) << "*10^" << slen1 << endl; 
//	}
//	return 0;
//}
//17��  
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
string a, b;

int main(){
	cin >> n >> a >> b;
	int pa, pb, pos1, pos2;	//	pa��pb��ʾ��������С����ʵ��λ�ã�pos1��2��ʾ��һ����Ч���ֵ�λ��
	if(a.find(".") == a.npos)
		a += ".0";
	if(b.find(".") == b.npos)	//	����С�����Ա�ͬһ����
		b += ".0";
	pa = a.find("."), pb = b.find(".");

	string aa = a, bb = b;	//	aa��bb���ս����ÿ������������Ч���֣������֣�
	aa.erase(aa.find("."), 1);
	bb.erase(bb.find("."), 1);	//	ȥ��С����
	pos1 = aa.find_first_not_of("0"), pos2 = bb.find_first_not_of("0");

	aa = pos1 == (int)aa.npos? "0" : string(aa, pos1, n);
	bb = pos2 == (int)bb.npos? "0" : string(bb, pos2, n);//	ע���ж�����0�������
	//	λ��������Ч���ָ�������0��
	while(aa.length() < n)	
		aa += '0';
	while(bb.length() < n)		
		bb += '0';
	int k1 = pa - pos1, k2 = pb - pos2;	//	ָ��
	//����0�������10��ָ���涨Ϊ0
	if(aa == string(n, '0'))
		k1 = 0;
	if(bb == string(n, '0'))	
		k2 = 0;
	string resa = "0." + string(aa, 0, n) + "*10^" + to_string(k1);
	string resb = "0." + string(bb, 0, n) + "*10^" + to_string(k2);
	if(resa == resb)
		cout << "YES " << resa << endl;
	else
		cout << "NO " << resa << ' ' << resb << endl;

	return 0;
}













 
