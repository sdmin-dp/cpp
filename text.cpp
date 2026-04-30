#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e5+5;
ll low_bit(ll x){
    return (x&(-x));
}
ll n,q;
ll tree[N];
void add(ll x,ll y){
    for(int i=x;i<=n;i+=low_bit(i)) tree[i]+=y;
}
ll get_sum(ll r){
    ll sum=0;
    for(int i=r;i>=1;i-=low_bit(i)) sum+=tree[i];
    cerr<<sum<<el;
    return sum;
    
}
void solve(){
    cin>>n>>q;
    ll last,x;
    cin>>last;
    ll a1=last;
    add(1,0);
    for(int i=2;i<=n;i++){
        cin>>x;
        add(i,x-last);
        last=x;
    }
    for(int i=1;i<=q;i++){
        ll op,l,r,k;
        cin>>op;
        if(op==1){
            cin>>l>>r>>k;
            add(l,k);
            add(r+1,-k);
        }else{
            cin>>k;
            cout<<get_sum(k)<<el;
        }
    }
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