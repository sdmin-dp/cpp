#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
ll l,r,D,U;
ll get_evens(ll l,ll r){
    if(l>r)return 0;
    auto f=[](ll n){
        if(n<0)return 0ll;
        return n/2+1;
    };
    if(l>=0)return f(r)-f(l-1);
    if(r<=0)return f(-l)-f(-r-1);
    return f(-l)+f(r)-1;
}
void solve(){
    if(!(cin>>l>>r>>D>>U))return;
    ll ans=0;
    for(ll y=D;y<=U;y++){
        ll ay=abs(y);
        ll mid_l=max(l,-ay),mid_r=min(r,ay);
        if(mid_l<=mid_r){
            if(ay%2==0)ans+=(mid_r-mid_l+1);
        }
        if(l<-ay)ans+=get_evens(l,min(r,-ay-1));
        if(r>ay)ans+=get_evens(max(l,ay+1),r);
    }
    cout<<ans<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    while(T--)solve();
    return 0;
}
