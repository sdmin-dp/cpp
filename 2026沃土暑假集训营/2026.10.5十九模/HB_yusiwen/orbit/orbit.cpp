#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,c,e;
ll ltime,wsum,isum;
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll cil(ll x,ll y){
    return (x%y==0?x/y:x/y+1);
}
void solve(){
    cin>>n>>c>>e;
    for(int i=1;i<=n;i++){
        ll d,v,a,b,k,r,f;
        cin>>d>>v>>a>>b>>k>>r>>f;
        //1.fly
        ltime+=cil(d,v);
        //2.in
        ll g=gcd(a,b);
        if(e<g){
            ll tmp=g-e;
            tmp=cil(tmp,r);
            ltime+=tmp;
            isum+=tmp;
            e+=tmp*r;
            if(e>c) e=c;
        }
        //3.wait
        ll l=a/g*b;
        ll t=cil(ltime,l);
        if(t%k==0) t++;
        ll wait=t*l-ltime;
        wsum+=wait;
        ltime+=wait;
        //4.pass
        e-=g;e+=f;
        if(e>c) e=c;
    }
    cout<<ltime<<" "<<wsum<<" "<<isum<<" "<<e;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("orbit.in","r",stdin);
    freopen("orbit.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}