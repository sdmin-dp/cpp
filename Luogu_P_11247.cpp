#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n,m,k;
ll a[N],cnt[N];
vector<ll> v[N];
void solve(){
    cin>>m>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        v[a[i]].push_back(x);
    }
    ll mx=0,id=0,ans=0;
    // for(int i=1;i<=m;i++){
    //     cout<<i<<":";
    //     for(auto j:v[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<'\n';
    // }
    for(int i=1;i<=m;i++){
        ll sum=0;
        sort(v[i].begin(),v[i].end(),greater<ll>());
        for(int j=0;j<v[i].size();j++){
            sum+=v[i][j];
            cnt[i]++;
            if(sum>=k) break;
        }
        if(sum<k){
            cout<<-1;
            return;
        } 
        ans+=cnt[i];
        if(cnt[i]>=mx) mx=cnt[i],id=i;
        
    }
    if(ans-mx>=mx-1){
        cout<<ans;
        // for(int i=1;i<=m;i++){
        //     cout<<cnt[i]<<" ";
        // }
    }
    else{
        ll mod=0;
        for(int i=1;i<=m;i++) if(i!=id) mod+=v[i].size()-cnt[i];
        if(ans-mx+mod>=mx-1){
            cout<<mx*2-1;
        }
        else{
            cout<<-1;
        }
    }
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