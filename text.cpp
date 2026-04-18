#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define el '\n'
const ll N=1e4;
bool isprime[10000];
int dist[10000];
void sieve(){
    isprime[0]=isprime[1]=1;
    for(int i=1;i<=N;i++){
        
    }
}
int bfs(int start, int end) {
    memset(dist, -1, sizeof dist);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();

        if (t == end) return dist[t];
        int p[4];
        p[0] = t / 1000;
        p[1] = t / 100 % 10;
        p[2] = t / 10 % 10;
        p[3] = t % 10;
        for (int i = 0; i < 4; i++) {
            int old = p[i];
            for (int j = 0; j <= 9; j++) {
                if (i == 0 && j == 0) continue;
                p[i] = j;
                int next_num = p[0] * 1000 + p[1] * 100 + p[2] * 10 + p[3];
                if (is_prime[next_num] && dist[next_num] == -1) {
                    dist[next_num] = dist[t] + 1;
                    q.push(next_num);
                }
            }
            p[i] = old;
        }
    }
    return -1;
}
void solve(){
    ll a,b;
    cin>>a>>b;
    ll res=bfs(a,b);
    if(res==-1) cout<<"Impossible"<<el;
    else cout<<res<<el;
}
int main() {
    ll T=1;
    cin>>T;
    sieve();
    while(T--){
        solve();
    }
    return 0;
}