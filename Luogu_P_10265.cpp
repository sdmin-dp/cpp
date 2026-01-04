#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+5;
ll n,b;
ll a[N][N];
ll ans1,ans2;
void solve(){
    cin>>n>>b;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        ans1+=a[b][i];
        ans2+=a[i][b];
    }
    cout<<ans1<<" "<<ans2<<" "<<ans1+ans2;
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