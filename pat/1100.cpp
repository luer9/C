#include <bits/stdc++.h>
using namespace std;
//��λ
string num[13]={
 "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug","sep", "oct", "nov", "dec"
};
//��λ
string num1[13]={
"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"
};
//string����ת����int����
int change_int(string s){
    int ans = 0 , len = s.length();
    for(int i = 0; i < len; i++) {
        ans = ans * 10 + (s[i] - '0');
    }
    return ans;
}
//����ת����string
string change1(int s){
    string temp = "";
    if(s < 13) {
        temp += num[s];
    }else {
        int A1,A2;
        A1 = s % 13; // ��λ 
        s /= 13;
        A2 = s % 13; //��λ
        if(A1 != 0) 
        temp = num1[A2] + " " + num[A1];
        else temp = num1[A2];
    }
    return temp;
}
int pos(string s) {
    
    for(int i = 0; i < 13; i++) {
        if(num[i] == s) return i;
    }
    return 0;
}
int pos1(string s){
    for(int i = 0; i < 13; i++) {
        if(num1[i] == s) return i; 
    }
    return 0;
}
//string ת���� ����
int change2(string s){
    int flag = 0; //���Ƿ��пո� ������¼λ��
    int len = s.length(), ans = 0; //���� �ʹ�
    for(int i = 0; i < len;i++) {
        if(s[i] == ' ') {
            flag = i; break;
        }
    }
    if(!flag) {
        ans = pos1(s)*13 + pos(s);
    }else {
        string temp = s.substr(0,flag);
        string temp1 = s.substr(flag+1);
        // cout << temp <<" " << temp1 << endl;
        
        ans = pos1(temp)*13 + pos(temp1);
    }
    return ans;
}
int main() 
{
    int t;
    string a;
    cin >> t;
    getchar();
    while(t--) {
        getline(cin, a);
        string ans;
        int ans1;
        if(a[0] >= '0' && a[0] <= '9'){
            int temp_a = change_int(a);
            ans = change1(temp_a);
            cout << ans << endl;
        }else {
            ans1 = change2(a);
            cout << ans1 << endl;
        }
    }
    return 0;
}