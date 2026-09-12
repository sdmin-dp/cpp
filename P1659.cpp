#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
const ll mod=19930726;
ll n,k,m;
string s;
ll p[N],d[N];
void manacher(){
    ll m=0,r=0;
    for(int i=0;i<s.size();i++){
        ll k=2*m-i;
        if(i<r) p[i]=min(r-i,p[k]);
        ll left=i-(1+p[i]),right=i+(1+p[i]);
        while(left>=0&&right<n&&s[left]==s[right]){
            p[i]++;
            left--;
            right++;
        }
        if(i+p[i]>r){
            m=i;
            r=i+p[i];
        }
    }
}
ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2) res=res*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return res;
}
void solve(){
    cin>>n>>k;
    cin>>s;
    manacher();
    for(int i=0;i<n;i++){
        p[i]=p[i]*2+1;
        d[1]++,d[p[i]/2+2]--;
        m=max(m,p[i]/2+2);
    }
    for(int i=1;i<=m;i++) d[i]+=d[i-1];
    ll ans=1;
    for(int i=m;i>=1;i--){
        if(k>=d[i]){
            ans=ans*qpow(i*2-1,d[i])%mod;
            k-=d[i];
        }
        else{
            ans=ans*qpow(i*2-1,k)%mod;
            cout<<ans;return;
        }
    }
    cout<<-1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}