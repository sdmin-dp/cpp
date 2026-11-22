#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m;
char a[N][N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        bool f=1;
        for(int j=1;j<=m;j++){
            if(a[i][j]!='x'){
                f=0;
                break;
            }
        }
        if(f){
            cout<<"Faucet "<<i<<el;
            return;
        }
    }
    for(int j=1;j<=m;j++){
        bool f=1;
        for(int i=1;i<=n;i++){
            if(a[i][j]!='x'){
                f=0;
                break;
            }
        }
        if(f){
            cout<<"Drain "<<j<<el;
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}