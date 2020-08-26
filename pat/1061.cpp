/*
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
*/
/*
前两个第一个大写的英文字母，第二个公共字符（无要求）
*/
#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
int len1, len2, len3, len4;
string week[10] = {"","MON","TUE","WED","THU","FRI","SAT","SUN"};
map<char,int> mac;
void init() {
    int ind = 0;
    for(int i = 0; i <= 9; i++) {
        mac[char(i + '0')] = i; 
        // cout << "i: "<< char(i + '0') <<endl;
    }
    for(int i = 10; i <= 23; i++) {
        mac[char('A' + i - 10)] = i;
        // cout << char('A' + i - 10) << endl;
    }
}
int main() {

    init();
    cin >> s1 >> s2 >> s3 >> s4;
    len1 = s1.length();
    len2 = s2.length();
    len3 = s3.length();
    len4 = s4.length();
    int flag = 0;
    for(int i = 0; i < max(len1, len2); i++) {
        if( s1[i] == s2[i] ) {
            if((s1[i] >= 'A' && s1[i] <= 'G') && flag == 0) {
                 cout << week[s1[i] - 'A' + 1] << " ";
                 flag ++;
            }
            else if(flag == 1 && (((s1[i] >= 'A' && s1[i] <= 'N')) || (s1[i]>='0' && s1[i] <= '9'))) {
                cout << setfill('0') << setw(2) << mac[s1[i]] << ":";
                break;
            } 
        }
    }
    for(int i = 0; i < max(len3, len4); i++) {
        if(s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z' )|| ( s3[i] >= 'A' && s3[i] <= 'Z' )) ) {
            cout << setfill('0') << setw(2) << i;
            break;
        }
    } 
    return 0;
}