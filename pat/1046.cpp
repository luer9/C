#include <bits/stdc++.h>
#define Max 100022
using namespace std;
int dis[Max];
int n, m;
int u, v;
int main() {
    memset(dis, 0, sizeof(dis));
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> dis[i];
        sum += dis[i];
        dis[i] = dis[i-1] + dis[i]; 
        //代表 1 到 i + 1 的距离
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        if( u > v ) swap(u, v);
        cout << min(dis[v - 1] - dis[u - 1], sum - (dis[v - 1] - dis[u - 1])) << endl; 
    }
    return 0;
}