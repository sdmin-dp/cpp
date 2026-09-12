#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m,fa[1400005];
ll cnt;
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=n+i;
        fa[n+i]=n+i;
    }
}
ll find(ll x){
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void add(ll x,ll y){
    ll fx=find(x),fy=find(y);
    if(fx!=fy){
        fa[fy]=fx;
    }
}
void erase(ll x){
    fa[x]=++cnt;
    fa[cnt]=cnt;
}
void solve(){
    cin>>n>>m;
    cnt=2*n;
    init();
    while(m--){
        ll op,x,y;
        cin>>op>>x;
        if(op==1){
            cin>>y;
            add(x,y);
        }else if(op==2){
            cin>>y;
            if(find(x)==find(y)){
                cout<<"Y/n";
            }else{
                cout<<"N/n";
            }
        }else if(op==3){
            erase(x);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}