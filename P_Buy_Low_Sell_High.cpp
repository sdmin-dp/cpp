#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e5+5;
ll n;
ll a[N];
priority_queue<ll,vector<ll>,greater<ll>> q;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    q.push(a[1]);
    ll ans=0;
    for(int i=2;i<=n;i++){
        q.push(a[i]);
        if(a[i]>q.top()){
            ans+=(a[i]-q.top());
            q.pop();
            q.push(a[i]);
        }
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