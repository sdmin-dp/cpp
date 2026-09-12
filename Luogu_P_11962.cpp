#include <bits/stdc++.h>
using namespace std;
#define ll long long
int num[1000005], vis[1000005], n, u, v;
vector<int> g[ 1000005];
void dfs(int x, int walk) {
    if(walk % 2 == 0) {
        num[2]++;
        vis[x]=2;
    }
    else{
        num[1]++;
        vis[x]=1;
    }
    for(int i=0;i<g[x].size();i++) {
        if(!vis[g[x][i]]) dfs(g[x][i], walk + 1);
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i ++) {
        cout << num[vis[i]] << ' ';
    }
    return 0;
}
