#include <bits/stdc++.h>
using namespace std;
int main(){
    int k; 
    string str;
    map<char,int> mapp;
    vector<int> book(256,0);
    vector<int> sure(256,0);
    cin >> k >> str;
    char pre = str[0];
    int cnt = 1, len = str.length();
    for(int i = 1; i < len; i++){
        if(str[i] == pre) {
            cnt++;
        }else {
            if(cnt % k != 0){
                sure[pre] = 1; //不是坏键
            }
            cnt = 1;
        }
        if(cnt % k == 0){
            mapp[pre] = 1; //是坏键
        }
        pre = str[i];
    }
    //避免了前面连续 后面不连续的 情况
    for(int i = 0; i < len; i++) {
        if(sure[str[i]] == 1) {
            mapp[str[i]] = 0;
        }
    }
    //输出坏键
    for(int i = 0; i < len; i++) {
        if(mapp[str[i]] == 1 && book[str[i]] == 0) {
            cout << str[i];
            book[str[i]] = 1;
        }
    }
    cout << endl;
    for(int i = 0; i < len;) {
        if(mapp[str[i]] == 1) {
            cout << str[i];
            i += k;
        }else {
            cout << str[i];
            i++;
        }
    }
    cout << endl;
    return 0;
}