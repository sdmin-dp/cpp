#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1025+5;
ll n;
bool a[N][N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
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