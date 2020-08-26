#include <bits/stdc++.h>
using namespace std;
/*
int main() {
    map<char,char> temp;
    map<string,int> vis;
    vis.clear();temp.clear();
    temp['1'] = '@';
    temp['0'] = '%';
    temp['l'] = 'L';
    temp['O'] = 'o';
    int n, cnt = 0;
    cin >> n;
    string user[1001],pwd[1001];
    for(int i = 0; i < n; i++) {
        cin >> user[i] >> pwd[i];
        int len = pwd[i].length(),flag = 0;
        for(int j = 0; j < len; j++) {
            if(pwd[i][j] == '1' || pwd[i][j] == '0' || pwd[i][j] == 'l' || pwd[i][j] == 'O') {
                flag = 1;
                pwd[i][j] = temp[pwd[i][j]];
            }
        }
        if(flag){
            cnt++;
            vis[user[i]] = 1;
        }
    } 
    if(!cnt) { // 如此之坑！！！！！！！！！！
        if(n == 1) {
            cout << "There is " << n << " account and no account is modified" << endl;
        }else    cout << "There are " << n << " accounts and no account is modified" << endl;
    }else {
        cout << cnt << endl;
        for(int i = 0; i < n; i++) {
            if(vis[user[i]] == 1) {
                cout << user[i] << " " << pwd[i] << endl;
            }
        }
    }
    return 0;
}
*/
//另一种比较清楚的写法  vector 和 pair
int main() {
    int n, len;
    string user,pwd;
    vector < pair <string, string> > vec;
    vec.clear();
    cin >> n;
    for(int i = 0 ; i < n;i ++){
        int flag = 0;
        cin >> user >> pwd;
        len = pwd.length();
        for(int j = 0; j < len; j++) {
            if(pwd[j] == '1') {
                pwd[j] = '@';
                flag = 1;
            }
            if(pwd[j] == '0') {
                pwd[j] = '%';
                flag = 1;
            }
            if(pwd[j] == 'l') {
                pwd[j] = 'L';
                flag = 1;
            }
            if(pwd[j] == 'O') {
                pwd[j] = 'o';
                flag = 1;
            }
        }

        if(flag) {
            vec.push_back( make_pair(user, pwd) );
        }
    }
    if(vec.size() == 0){
        if(n == 1) {
            cout << "There is " << n << " account and no account is modified" << endl;
        }else cout << "There are " << n << " accounts and no account is modified" << endl;
    }else 
    {
        cout << vec.size() << endl;
        for(auto it : vec) {
            cout << it.first << " " << it.second << endl;
        }
    }
    return 0;
}