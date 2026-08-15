#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,k;
ll a[N];
ll ans[N];
deque<ll> dq;
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        while(!dq.empty()&&dq.front()<i-k+1){
            dq.pop_front();
        }
        while(!dq.empty()&&a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            ans[i]=a[dq.front()];
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}

int main() {
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