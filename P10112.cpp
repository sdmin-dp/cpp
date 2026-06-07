#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+1;
const ll mod=1e9+7;
ll n,m;
ll c[N+5][N+5];
ll a[N+5];
void init(){
    for(int i=0;i<=N;i++){
        c[i][0]=1;
        c[i][i]=1;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
}
void solve(){
    cin>>n>>m;
    ll sum=0;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll cnt=1;
    if(sum==n||sum==n+1){
        for(int i=1;i<=m;i++){
            cnt=(cnt*c[sum][a[i]])%mod;
            sum-=a[i];
        }
        cout<<cnt;
    }else{
        cout<<0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    init();
    ll T=1;
    cin>>T;
    while(T--){
        solve();
        cout<<el;
    }
    return 0;
}