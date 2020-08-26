#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main() {
	ll p;
    int n;
    cin >> n >> p;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int result = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + result; j < n; j++) {
            if (v[j] <= v[i] * p) {
                temp = j - i + 1;
                if (temp > result)
                    result = temp;
            }else {
                break;
            }
        }
    }
    cout << result;
    return 0;
}
