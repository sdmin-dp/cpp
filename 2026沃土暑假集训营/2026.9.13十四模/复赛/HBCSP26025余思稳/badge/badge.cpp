#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n,k;
ll b[N];
void solve(){
    cin>>n>>k;
    ll mx=-1e12;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        mx=max(mx,b[i]);
    }
    sort(b+1,b+n+1,greater<ll>());
    ll res=0;
    for(int I=1;I<=mx;I++){
        ll cnt=0;
        vector<ll> tmp;
        for(int i=1;i<=n;i++){
            cnt+=(b[i]/I);
            tmp.push_back(b[i]%I);
        }
        if(cnt<k/2) continue;
        ll ans=0;
        if(cnt>=k) ans=k/2*I;
        else{
            ans=(cnt-k/2)*I;
            sort(tmp.begin(),tmp.end(),greater<ll>());
            for(int i=0;i<k-cnt;i++) ans+=tmp[i];
        }
        res=max(res,ans);
    }
    cout<<res;
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