#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
struct  node{
    ll d,a,b,k,r,f;
}a[N];
ll n,c,e,D,V;
ll ltime,wsum,isum,esum;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll cil(ll x,ll y){
    return (x%y==0?x/y:x/y+1);
}
bool check(ll v){
    ll ltime=0,wsum=0,isum=0,esum=e;
    for(int i=1;i<=n;i++){
        // cin>>a[i].d>>a[i].a>>a[i].b>>a[i].k>>a[i].r>>a[i].f;
        //1.fly
        ltime+=cil(a[i].d,v);
        //2.in
        ll g=gcd(a[i].a,a[i].b);
        if(esum<g){
            ll tmp=g-esum;
            tmp=cil(tmp,a[i].r);
            ltime+=tmp;
            isum+=tmp;
            esum+=tmp*a[i].r;
            if(esum>c) esum=c;
        }
        //3.wait
        ll l=a[i].a/g*a[i].b;
        ll t=cil(ltime,l);
        if(t%a[i].k==0) t++;
        ll wait=t*l-ltime;
        wsum+=wait;
        ltime+=wait;
        //4.pass
        esum-=g;esum+=a[i].f;
        if(esum>c) esum=c;
    }
    return (ltime<=D);
}
ll erfen(){
    ll l=1,r=V,mid=0,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}
void solve(){
    cin>>n>>c>>e>>V>>D;
    esum=e;
    for(int i=1;i<=n;i++){
        cin>>a[i].d>>a[i].a>>a[i].b>>a[i].k>>a[i].r>>a[i].f;
        //1.fly
        ltime+=cil(a[i].d,V);
        //2.in
        ll g=gcd(a[i].a,a[i].b);
        if(esum<g){
            ll tmp=g-esum;
            tmp=cil(tmp,a[i].r);
            ltime+=tmp;
            isum+=tmp;
            esum+=tmp*a[i].r;
            if(esum>c) esum=c;
        }
        //3.wait
        ll l=a[i].a/g*a[i].b;
        ll t=cil(ltime,l);
        if(t%a[i].k==0) t++;
        ll wait=t*l-ltime;
        wsum+=wait;
        ltime+=wait;
        //4.pass
        esum-=g;esum+=a[i].f;
        if(esum>c) esum=c;
    }
    if(ltime>D){
        cout<<-1;
        return;
    }
    ltime=0,wsum=0,isum=0,esum=e;
    ll v=erfen();
    for(int i=1;i<=n;i++){
        // cin>>a[i].d>>a[i].a>>a[i].b>>a[i].k>>a[i].r>>a[i].f;
        //1.fly
        ltime+=cil(a[i].d,v);
        //2.in
        ll g=gcd(a[i].a,a[i].b);
        if(esum<g){
            ll tmp=g-esum;
            tmp=cil(tmp,a[i].r);
            ltime+=tmp;
            isum+=tmp;
            esum+=tmp*a[i].r;
            if(esum>c) esum=c;
        }
        //3.wait
        ll l=a[i].a/g*a[i].b;
        ll t=cil(ltime,l);
        if(t%a[i].k==0) t++;
        ll wait=t*l-ltime;
        wsum+=wait;
        ltime+=wait;
        //4.pass
        esum-=g;esum+=a[i].f;
        if(esum>c) esum=c;
    }
    cout<<v<<el;
    cout<<ltime<<" "<<wsum<<" "<<isum<<" "<<esum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("orbit.in","r",stdin);
    // freopen("orbit.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}