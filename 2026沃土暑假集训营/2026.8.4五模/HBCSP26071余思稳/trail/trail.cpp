#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,q;
ll a[N],sum[N];
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=q;i++){
        ll l,x;
        cin>>l>>x;
        ll pos=lower_bound(sum+l,sum+n+1,x+sum[l-1])-sum;
        if(pos==n+1){
            cout<<n-l+1<<" "<<x-(sum[n]-sum[l-1])<<el;
            continue;
        }
        if(sum[pos]-sum[l-1]>x) pos--;
        cout<<pos-l+1<<" "<<x-sum[pos]+sum[l-1]<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("trail.in","r",stdin);
    freopen("trail.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
5 3
3 3 3 3 3
1 14
3 6
5 3
*/
