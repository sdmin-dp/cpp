#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=17;i<=100;i++){
        ll l=i-17,r=i;
        ll posl=lower_bound(a+1,a+n+1,l)-a-1,posr=lower_bound(a+1,a+n+1,r)-a;
        
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("stage.in","r",stdin);
    // freopen("stage.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}