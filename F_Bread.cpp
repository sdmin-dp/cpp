#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,len;
ll a[N];
priority_queue<ll,vector<ll>,greater<ll>> q;
void solve(){
    cin>>n>>len;
    ll ans=0;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q.push(a[i]);
        sum+=a[i];
    }
    if(len-sum!=0) q.push(len-sum);
    while(q.size()>1){
        ll t1=q.top();q.pop();
        ll t2=q.top();q.pop();
        ans+=t1+t2;
        q.push(t1+t2);
    }
    cout<<ans;
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