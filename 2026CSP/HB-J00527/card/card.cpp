#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n,m;
ll a[N];
ll d[N];
ll cnt[N],vs[N];
ll id[N];
bool checkA(){
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1]){
            return 0;
        }
    }
    return 1;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(checkA()){
        vector<ll> vis(m+1,0);
        for(int i=1;i<=n;i++){
            vis[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<vis[i]<<" ";
        }
    }else if(m==1){
        cout<<n;
    }else if(m==2){
        ll ans[3]={0,0,0};
        for(int i=1;i<=n;i++){
            if(a[i]==a[n]){
                ans[a[i]]++;
            }else if(a[i]!=a[n]){
                ans[a[i]]++;
                ans[a[n]]++;
            }
        }
        cout<<ans[1]<<" "<<ans[2];
    }else{
        for(int i=1;i<=n;i++){
            memset(d,0,sizeof(d));
            memset(vs,0,sizeof(cnt));
            memset(id,0,sizeof(id));
            for(int j=i;j<=n;j++){
                if(id[a[j]]!=0){
                    for(int k=i;k<=n;k++){
                        d[k]+=d[k-1];
                    }
                    if(d[id[a[j]]]==0){
                        d[id[a[j]]]++;
                        d[j]--;
                    }
                }
                id[a[j]]=j;
            }
            for(int j=i;j<=n;j++){
                d[j]+=d[j-1];
            }
            for(int j=i;j<=n;j++){
                if(d[j]==0){
                    vs[a[j]]=1;
                }
            }
            for(int i=1;i<=m;i++){
                cnt[i]+=vs[i];
            }
        }
        for(int i=1;i<=m;i++){
            cout<<cnt[i]<<" ";
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}