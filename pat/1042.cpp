/*
your task is to simulate��ģ�£� a shuffling machine
���������ģ��һ���Զ�ϴ�ƻ���
�����i��λ�õ�����j����˼���ƶ���Ƭ��λ��i��j
*/
#include <bits/stdc++.h>
using namespace std;
string cards[55];
void init(){
    int indx = 1;
    for(int i = 1; i <= 13; i++) {
        cards[indx++] = "S" + to_string(char(i));
    }
    for(int i = 1; i <= 13; i++) {
        cards[indx++] = "H" + to_string(char(i));
    }
       for(int i = 1; i <= 13; i++) {
        cards[indx++] = "C" + to_string(char(i));
    }
       for(int i = 1; i <= 13; i++) {
        cards[indx++] = "D" + to_string(char(i));
    }
       for(int i = 1; i <= 2; i++) {
        cards[indx++] = "J" + to_string(char(i));
    }
}

int main() {
    init();
    // for(int i = 1; i <= 54; i++){
    //     cout << cards[i] << " " ;
    // }
    int k, lis[55];
    cin >> k;
    for(int i = 1; i <= 54; i++) {
        cin >> lis[i];
    }
    string temp[55];
    while(k--) {
        for(int i = 1; i <= 54; i++) {
            temp[lis[i]] = cards[i];
        }
        for(int i = 1; i <= 54; i++) {
            cards[i] = temp[i];
        }
    }
    for(int i = 1; i <= 54; i++) {
        cout << cards[i];
        if( i != 54) cout << " " ;
    }
    cout << endl;
    return 0;
}