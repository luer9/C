#include <bits/stdc++.h>
#define Max 1111
using namespace std;
//²¢²é¼¯
int fa[Max];
vector <int> vec[Max];
int n, m, k, u, v, x;
void init() {
    for (int i = 0; i<= n ; i++){
        fa[i] = i;
    }
}
void init1() {
    for (int i = 1; i <= n; i++){
        vec[i].clear();
    }
}
int Find (int x) {
    if (fa[x] == x) return x;
    return  fa[x] = Find(fa[x]);
}
int mix(int x, int y) {
    int fx = Find(x);
    int fy = Find(y);
    if (fx != fy) {
        fa[fx] = fy;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> n >> m >> k) {
        init1();
        for (int i = 0; i < m; i++){
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        for (int ii = 0; ii < k; ii++){
            cin >> x;
            init ();
            for (int i = 1; i <= n; i++){
                for (int j = 0; j < vec[i].size(); j++){
                    int u = i, v = vec[i][j];
                    if(x == u || x == v ) {
                        continue;
                    }
                    mix(u, v);
                    // cout << "--> " << u << " " << v <<endl;
                }
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++){
                if (i == x) continue;
                if (fa[i] == i) cnt++;
            }
            cout << cnt - 1 <<endl;
    }return 0;
}
}