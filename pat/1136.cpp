#include <bits/stdc++.h>
using namespace std;
int isPal(string num) {
	int len = num.length();
	for(int i = 0; i < len; i ++) {
		if(num[i] != num[len - i - 1]) {
			return 0;//���ǻ���
		}
	}
	return 1;//�ǻ���
}
string s;
int num1[1102]= {0},num2[1102]= {0},num[1102]= {0};
int main() {
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt", "r", stdin);
#endif
	int cnt = 0;
	cin >> s; 
	//Ҫ�ж�  �տ�ʼ�� �ǲ��ǻ��Ĵ� ���� �м���������������ȥ 
	if(isPal(s)){
		cout << s << " is a palindromic number." << endl;
		return 0;
	}
	while(1) {
		cnt++;
		if(cnt > 10) {
			cout << "Not found in 10 iterations." << endl;
			return 0;
		}
		int index = 0;
		int len = s.length();
		//s ת�� ����
		for(int i = 0; i < len; i++) {
			num1[index] = (s[i]-'0');
			num2[index++] = (s[len - i - 1] - '0');
		}
		// �����
		for(int i = 0; i < index; i++) {
			num[i] = num1[i] + num2[i];
		}
		int c = 0;
//		for(int i = 0; i < index; i++) {
//			cout << num[i] << " ";
//		}
//		cout << endl;
		for(int i = 0; i < index; i++) {
			num[i] = num[i] + c;
			c = num[i] / 10;
			num[i] %= 10;
		}
		if(c!=0) {
			num[index] = c;
			index++;
		}
//		for(int i = 0; i < index; i++) {
//			cout << num[i] << " ";
//		}
//		cout << endl;
		for(int i = 0; i < len; i++){
			cout << s[i];
		}
		cout << " + ";
		for(int i = 0; i < len; i++){
			cout << s[len - i - 1];
		}
		string ans = "";
		for(int i = index-1; i >= 0; i--){
			ans += (num[i] + '0');
		}
		cout << " = " ;
		cout << ans << endl; 
		s = ans;
		if(isPal(ans)){
			cout << ans << " is a palindromic number." << endl;
			return 0;
		}
	}
	return 0;
}


/*
���񾫼�Ĵ��� 
#include <iostream>
#include <algorithm>
using namespace std;
string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}
string add(string s1, string s2) {
    string s = s1;
    int carry = 0;
    for (int i = s1.size() - 1; i >= 0; i--) {
        s[i] = (s1[i] - '0' + s2[i] - '0' + carry) % 10 + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
    }
    if (carry > 0) s = "1" + s;
    return s;
}
int main() {
    string s, sum;
    int n = 10;
    cin >> s;
    if (s == rev(s)) {
        cout << s << " is a palindromic number.\n";
        return 0;
    }
    while (n--) {
        sum = add(s, rev(s));
        cout << s << " + " << rev(s) << " = " << sum << endl;
        if (sum == rev(sum)) {
            cout << sum << " is a palindromic number.\n";
            return 0;
        }
        s = sum;
    }
    cout << "Not found in 10 iterations.\n";
    return 0;
}
*/ 
