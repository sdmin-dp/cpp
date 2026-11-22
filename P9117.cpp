#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;

void solve(){
    ll n,m,q;
    cin>>n>>m>>q;
    vector<pair<ll,ll>> h(n+1),l(m+1);
    for(int i=1;i<=q;i++){
        ll op,x,c;
        cin>>op>>x>>c;
        if(op==0) h[x]={c,i};
        else l[x]={c,i};
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(h[i].second>l[j].second) cout<<h[i].first<<" ";
            else cout<<l[j].first<<" ";
        }
        cout<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}