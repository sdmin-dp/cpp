#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,k;
string s;
ll c[N];
ll base[N];
ll suf[N];
void solve(){
    cin>>n>>k>>s;
    for(int i=0;i<n;i++) cin>>c[i];
    ll mn=0;
    for(int i=0;i<n-i-1;i++){
        int j=n-i-1;
        if(s[i]==s[j]) base[i]=0;
        else base[i]=min(c[i],c[j]);
        mn+=base[i];
    }
    if(mn>k){
        cout<<-1;
        return;
    }
    int m=n/2;
    suf[m]=0;
    for(int i=m-1;i>=0;i--) suf[i]=suf[i+1]+base[i];
    for(int i=0;i<m;i++){
        int j=n-i-1;
        ll left=k-suf[i+1];
        for(int d=9;d>=0;d--){
            ll cost=0;
            if(s[i]-'0'!=d) cost+=c[i];
            if(s[j]-'0'!=d) cost+=c[j];
            if(cost<=left){
                s[i]=s[j]='0'+d;
                k-=cost;
                break;
            }
        }
    }
    if(n%2){
        int i=n/2;
        for(int d=9;d>=0;d--){
            ll cost=(s[i]-'0'!=d?c[i]:0);
            if(cost<=k){
                s[i]='0'+d;
                k-=cost;
                break;
            }
        }
    }
    cout<<s;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("mirror.in","r",stdin);
    // freopen("mirror.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
