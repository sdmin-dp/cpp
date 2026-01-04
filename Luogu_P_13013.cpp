#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m,a,b;
bool check(ll mid)
{
    ll sa=mid*a,sb=mid*b,tmp;
    if(sa>n){
        tmp=(sa-n+a-b-1)/(a-b);
        sa-=tmp*(a-b);
        sb+=tmp*(a-b);
    }
    if(sa<=n&&sb<=m)return 1;
    return 0;
}
ll rf(){
    ll l=1,r=1e9,mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
void solve(){
    cin>>n>>m>>a>>b;
    if(a<b) swap(a,b);
    if(n<m) swap(n,m);
    if(a==b){cout<<m/a;return;}
    cout<<rf();
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