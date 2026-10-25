#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m,ans;
ll a[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]==m){
        ans++;
    }
    for(int i=2;i<=n;i++){
        if((a[i-1]<m&&a[i]>m)||(a[i-1]>m&&a[i]<m)){
            ans++;
        }
        else if(a[i]==m){
            ans++;
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}