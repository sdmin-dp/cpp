#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
const ll mod=1e9+7;
ll n,q;
string s;
ll nxt[N];
void solve(){
    cin>>n>>q;
    cin>>s;
    ll ans=0;
    while(q--){
        ll x;string t;
        cin>>t;
        cin>>x;
        ll m=t.size();
        memset(nxt,0,sizeof(nxt));
        for(int i=1,j=0;i<m;i++){
            while(j>0&&t[i]!=t[j]) j=nxt[j-1];
            if(t[i]==t[j]) j++;
            nxt[i]=j; 
        }
        ll cnt=0;
        for(int i=0,j=0;i<n;i++){
            while(j>0&&s[i]!=t[j]) j=nxt[j-1]; 
            if(s[i]==t[j]) j++;
            if(j==m){
                cnt++;
                j=nxt[j-1]; 
            }
        }
        ans=(ans+(cnt*m*x)%mod)%mod;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("echo.in","r",stdin);
    freopen("echo.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}