//radix 基数
//如果 tag == 1  基数是N1的基数
//如果 tag == 2  基数是N2的基数
// 题中给的 已经基数 转换 后是不会溢出的
// radix_下限：遍历位置数的每一位，得到单个位的最大值 + 1
// radix_上限：因为如果N1 = N2 那么未知数的基数不可能 大于 已知数
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