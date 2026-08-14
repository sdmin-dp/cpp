#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N],b[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    m=unique(b+1,b+n+1)-b-1;
    cerr<<m;
    for(int i=1;i<=n;i++){
        ll pos=lower_bound(b+1,b+m+1,a[i])-b;
        cout<<pos-1<<el;
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