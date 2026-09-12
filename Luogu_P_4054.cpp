#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=305+5;
ll n,m,q;
ll a[N][N],t[N][N][N];
ll lowbit(ll x){
    return x&(-x);
}
void add(ll x,ll y,ll c,ll d){
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=m;j+=lowbit(j)){
            t[i][j][c]+=d;
        }
    }
}
ll getsum(ll x,ll y,ll c){
    ll res=0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            res+=t[i][j][c];
        }
    }
    return res;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            add(i,j,a[i][j],1);
        }
    }
    cin>>q;
    ll op;
    while(q--){
        cin>>op;
        if(op==1){
            ll x,y,c;
            cin>>x>>y>>c;
            add(x,y,a[x][y],-1);
            a[x][y]=c;
            add(x,y,a[x][y],1);
        }
        else{
            ll x1,y1,x2,y2,c;
            cin>>x1>>x2>>y1>>y2>>c;
            ll ans=getsum(x2,y2,c)-getsum(x1-1,y2,c)-getsum(x2,y1-1,c)+getsum(x1-1,y1-1,c);
            cout<<ans<<"\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}