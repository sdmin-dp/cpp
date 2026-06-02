#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=50+5;
ll n,l,r;
ll a[N];
ll c[N][N];
map<ll,ll,greater<ll>> mp;
void init(){
    for(int i=0;i<=50;i++){
        c[i][0]=1;
        c[i][i]=1;
    }
    for(int i=0;i<=50;i++){
        for(int j=1;j<i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    // for(int i=0;i<=50;i++){
    //     for(int j=0;j<=i;j++){
    //         cerr<<c[i][j]<<" ";
    //     }
    //     cerr<<el;
    // }
}
void solve(){
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a+1,a+n+1,greater<ll>());
    ll ans=0;
    for(int i=l;i<=r;i++){
        if(i==l||a[i]==a[1]){
            ll x=mp[a[i]],y=i;
            for(auto p:mp){
                if(p.first>a[i]) y-=p.second;
                else break;
            }
            ans+=c[x][y];
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    init();
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}