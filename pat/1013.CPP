#include <bits/stdc++.h>
#define Max 1111
using namespace std;
int mapp[Max][Max];
int vis[Max];
int n, m, k, u, v;
void dfs (int u) {
    vis[u] = 1;
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i] && mapp[u][i])
        {
            dfs(i);
        }
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m >> k) {
        memset(mapp, 0, sizeof(mapp));
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            mapp[u][v] = mapp[v][u] = 1;            
        }
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt = 0;
            memset(vis, 0,sizeof(vis));
            cin >> u;
            vis[u] = 1;
            for (int j = 1;j <= n;j++) {
                if (!vis[j]) {
                    dfs(j);
                    cnt++; //连通块的个数
                }
            }
            cout << cnt - 1 <<endl;
        }
        
    }
    return 0;
}

