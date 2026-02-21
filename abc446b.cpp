#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n,m;
vector<ll> g[N];
bool flag[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll s;cin>>s;
        for(int j=1;j<=s;j++){
            ll x;cin>>x;
            g[i].push_back(x);
        }
    }    
    for(int i=1;i<=n;i++){
        bool b=0;
        for(auto j:g[i]){
            if(!flag[j]){
                b=1;
                cout<<j<<el;
                flag[j]=1;
                break;
            }
        }
        if(!b) cout<<0<<el;
    }
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