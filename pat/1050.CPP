#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int main() 
{
    getline(cin, s1);
    getline(cin, s2);
    int len1 = s1.length();
    int len2 = s2.length();
    for(int i = 0; i < len1; i++) {
        int flag = 0;
        for(int j = 0; j < len2; j++){
            if(s1[i] == s2[j]) {
                flag = 1;
            }
        }
        if(!flag) cout << s1[i];
    }
    cout << endl;
    return 0;
}