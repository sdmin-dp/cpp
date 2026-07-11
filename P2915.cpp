#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=12+5;
const ll S=(1<<13)+5;
const ll mod=1e8;
ll n,m,s,x,ans,f[N][S],t[N],g[S];
void solve(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            t[i]=(t[i]<<1)+x;
        }
    }
    s=1<<n;
    for(int i=0;i<s;i++){
        g[i]=((i&(i<<1))==0);
    }
    f[0][0]=1;
    for(int i=1;i<=m;i++)
        for(int j=0;j<s;j++)
            if(g[j]&&(j&t[i])==j)
                for(int k=0;k<s;k++)
                    if(!(j&k))
                        f[i][j]+=f[i-1][k];
    for(int i=0;i<s;i++) ans=(ans+f[m][i])%mod;
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}