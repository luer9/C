#include <iostream>
#define inf 0x3f3f3f
using namespace std;
int main(){
    int minn = inf,maxx = -inf;
    int ans = 0, a, n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a < minn){
            minn = a;
        }
        if(a > maxx){
            maxx = a;
        }
        ans += a;
    }
    cout << maxx << endl << minn << endl << ans << endl;
    return 0;
}