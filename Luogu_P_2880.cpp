#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m;
ll a[N];
ll mx[N],mn[N];
ll lowbit(ll x){
     return (x&-x);
}
ll getmx(ll x,ll y){
    ll t=0;
    while(y>=x){
        if(y-lowbit(y)>x){
            t=max(t,mx[y]);
            y-=lowbit(y);
        }
        else{
            t=max(t,a[y]);
            y--;
        }
    }
    return t;
}
void addmx(ll x,ll d){
    while(x<=n){
        mx[x]=max(d,mx[x]);
        x+=lowbit(x);
    }
}
ll getmn(ll x,ll y){
    ll t=INT_MAX;
    while(y>=x){
        if(y-lowbit(y)>x){
            t=min(t,mn[y]);
            y-=lowbit(y);
        }
        else{
            t=min(t,a[y]);
            y--;
        }
    }
    return t;
}
void addmn(ll x,ll d){
    while(x<=n){
        mn[x]=min(d,mn[x]);
        x+=lowbit(x);
    }
}
void solve(){
    cin>>n>>m;
    memset(mn,0x3f,sizeof(mn));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        addmx(i,a[i]);
        addmn(i,a[i]);
    }
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        ll u=getmx(x,y),v=getmn(x,y);
        cout<<u-v<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}