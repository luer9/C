//radix ����
//��� tag == 1  ������N1�Ļ���
//��� tag == 2  ������N2�Ļ���
// ���и��� �Ѿ����� ת�� ���ǲ��������
// radix_���ޣ�����λ������ÿһλ���õ�����λ�����ֵ + 1
// radix_���ޣ���Ϊ���N1 = N2 ��ôδ֪���Ļ��������� ���� ��֪��
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string N1, N2;
int tag;
ll radix=0,result_radix;
ll convert(string n,ll radix){
    ll sum = 0;
    int index = 0, temp = 0;
    for(auto it = n.rbegin();it != n.rend(); it++) {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}
ll find_radix(string n,ll num){
    char it = *max_element(n.begin(), n.end());
    ll low = (isdigit(it)?it - '0' : it - 'a' + 10) + 1;
    ll high = max(num ,low);
    while (low <= high) {
        ll mid = (low+high) >> 1;
        ll t = convert(n,mid);
        if(t < 0 || t > num) high = mid - 1;
        else if( t == num ) return mid;
        else low = mid + 1;
    }
    return -1;
}
int main(){
    
    cin >> N1 >> N2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(N2, convert(N1,radix)) : find_radix(N1, convert(N2,radix));
    if (result_radix != -1){
        cout << result_radix << endl;
    }else {
        cout << "Impossible" <<endl;
    }
    return 0;
} 