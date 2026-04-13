#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<n;i++) cin>>a[i];
    ll cnt=1;
    for(int i=1;i<n;i++){
        // cerr<<cnt<<" "<<m<<el;
        // if(cnt>m) break;
        
        if(cnt==m){
            cout<<"YES\n";
            // cerr<<el;
            return;
        }
        cnt+=a[cnt];
    }
    cout<<"NO\n";
    // cerr<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}