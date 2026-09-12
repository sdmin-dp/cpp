#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll d,n,m,t;
deque<ll> dq;
void solve(){
    cin>>d>>n>>m>>t;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        dq.push_back(x);
    }
    ll k=0;
    for(int i=0;i<t;i++){
        if(i%m==0){
            ll x=dq.back();
            dq.pop_back();
            dq.push_front(x);
        }
        k+=dq[i%n];
        k%=d;
    }
    cout<<k%d;
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