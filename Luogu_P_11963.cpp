#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=4e5+5;
ll n;
ll a[N];
ll res=INT_MIN,mx=0,ans=INT_MAX,mn=0,sum;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(a[i],mx+a[i]);
        res=max(res,mx);


        mn=min(a[i],mn+a[i]);
        ans=min(ans,mn);

        
        sum+=a[i];
    }
    // cerr<<res<<" "<<ans<<'\n';
    if(sum-ans==0) cout<<res;
    else cout<<max(res,sum-ans);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}