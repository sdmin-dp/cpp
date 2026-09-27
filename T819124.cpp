#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;

void solve(){
    ll n,r;
    cin>>n>>r;
    ll a=(n+1)/2,b=a;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(sqrt((i-a)*(i-a)+(j-b)*(j-b))<=r) cout<<'#';
            else cout<<'.';
        }
        cout<<el;
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