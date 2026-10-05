#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,q,k,x,y,r;
ll a[1505][1505],ans;
void solve(){
    cin>>n>>m>>q>>k;
    for(int l=1;l<=q;++l){
        cin>>x>>y>>r;
        for(int i=max(0ll,x-r);i<=min(n,x+r);++i)
            for(int j=max(0ll,y-r);j<=min(m,y+r);++j)
                if(abs(i-x)+abs(j-y)<=r)
                    ++a[i][j];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) 
            if(a[i][j]>=k) ++ans;
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("lantern.in","r",stdin);
    freopen("lantern.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}