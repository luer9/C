#include <bits/stdc++.h>
using namespace std;
int main(){
    string s0,s1;
    cin >> s0 >> s1;
    int len0 = s0.length();
    int len1 = s1.length();
    map<char,int> map0;  
    map0.clear();
    map<char,int> map1;
    map1.clear();
    for(int i = 0; i < len0; i++) {
        map0[s0[i]] ++;
    }
    for(int i = 0; i < len1; i++) {
        map1[s1[i]] ++;
    }
    int flag = 0;//È±²»È±
    int cnt = 0;//È±¼¸¸ö
    for(int i = 0; i < len1; i++) {
        if(map0[s1[i]] >= map1[s1[i]]) {
            map0[s1[i]] --;
            map1[s1[i]] --;
            continue;
        }
        flag = 1;
        cnt += map1[s1[i]] - map0[s1[i]];
        map0[s1[i]] = map1[s1[i]] = 0;
    }
    if(!flag) {
        cout << "Yes" << " " << len0 - len1 << endl;
    }else {
        cout << "No" << " " << cnt << endl;
    }
    return 0;
}
