#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e5+5;
const ll AN=5e6;
const ll mod=1e9+7;
ll n;
ll a[N];
bool vis[AN+5];
ll f[AN+5];
map<ll,ll> ct;
vector<ll> prime;
void init(){
    for(ll i=2;i<=AN;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(ll j=i*i;j<=AN;j+=i){
                vis[j]=1;
            }
        }
    }
    f[0]=1;
    for(ll i=1;i<=AN;i++){
        f[i]=f[i-1]*2%mod;
    }
}
void solve(){
    init();
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        for(auto x:prime){
            if(a[i]==1){
                break;
            }
            if(!vis[a[i]]){
                if(a[i]>1){
                    ct[a[i]]++;
                }
                break;
            }
            bool flag=0;
            while(a[i]%x==0){
                if(!flag){
                    ct[x]++;
                    flag=1;
                }
                a[i]/=x;
            }
        }
    }
    ll ans=0;
    for(auto x:ct){
        ll k=x.second;
        ll tmp=(f[k]-1)*f[n-k]%mod;
        ans=(ans+tmp)%mod;
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