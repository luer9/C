#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
ll mapp[1000][1000];
map<ll, int> vis;
int main() {
    memset(mapp, 0, sizeof(mapp));
    vis.clear();
    ll ans = 0, cnt = -1;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mapp[i][j];
            vis[mapp[i][j]] ++;
            if(vis[mapp[i][j]] > cnt) {
                cnt = vis[mapp[i][j]];
                ans = mapp[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}