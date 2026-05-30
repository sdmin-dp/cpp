/*
先选出k对手套:
c(n,k)
然后在从n-k对里面选出m-2k对，每对选一支:
c(n-k,m-2k)
最后每对还分左右手，乘2:
2^(m-2k)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e3;
const ll mod=1e9+7;
ll n,m,k;
ll c[N+5][N+5];
ll pow2[N+5];
void init(){
    c[0][0]=1;
    pow2[0]=1;
    for(int i=1;i<=N;i++){
        pow2[i]=(pow2[i-1]*2)%mod;
    }
    for(int i=1;i<=N;i++){
        c[i][0]=1;
        c[i][i]=1;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
}
void solve(){
    cin>>n>>m>>k;
    if(m<2*k||n<k){
        cout<<0<<el;
        return;
    }
    cout<<(((c[n][k]%mod)*(c[n-k][m-2*k]%mod)%mod)*(pow2[m-2*k]%mod)%mod)<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    init();
    while(T--){
        solve();
    }
    return 0;
}