#include <iostream>
#include <cstring>
#include <map>
using namespace std;
map<int,int> mapp;
int n,a,key;
int main(){

    mapp.clear();
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(mapp[a] == 0) {
            mapp[a] = i+1;
        }
    }
    cin >> key;
    if(mapp[key] != 0) {
        cout << mapp[key] << endl;
    }else cout << "-1" << endl;
    return 0;
}