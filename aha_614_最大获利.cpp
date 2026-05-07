#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
ll n,m,k;
vector<vector<pair<ll,ll>>> g;
ll eat[N];
ll dis[N][25];
void init(){
    g.clear();
    memset(eat,0,sizeof(eat));
    memset(dis,0x3f,sizeof(dis));
}
void solve(){
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        init();
        solve();
    }
    return 0;
}