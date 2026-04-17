#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n;
ll dis[N][N];
void solve(){
    cin>>n;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bool x;
            cin>>x;
            if(x!=0) dis[i][j]=x;
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