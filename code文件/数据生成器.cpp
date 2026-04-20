#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;

void solve(){
    ll t=10000;
    cout<<t<<el;
    for(int i=1;i<=t;i++){
        ll n=rand()%200001;
        cout<<n<<el;
        for(int i=1;i<=n;i++){
            ll a=rand()%(n+1);
            cout<<a<<" ";
        }
        cout<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    srand(time(0));
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}