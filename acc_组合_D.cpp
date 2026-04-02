#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,p,ny[10000005]; 
void solve(){
    cin>>n>>p;
    ny[1]=1;cout<<1<<'\n';
    for(int i=2;i<=n;i++){
        ny[i]=(p-p/i)*ny[p%i]%p;
        cout<<ny[i]<<'\n';
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