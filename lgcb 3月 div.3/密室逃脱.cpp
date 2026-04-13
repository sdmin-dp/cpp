#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m,x;
void solve(){
    cin>>n>>m;
    ll cnt=1;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(cnt==m){
            cout<<"YES\n";
            cerr<<el;
            return;
        }
        cnt+=x;
        cerr<<cnt<<" ";
    }
    cout<<"NO\n";
    cerr<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}