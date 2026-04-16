#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,k;
ll a[N];
void solve(){
    n=rand()%20,k=rand()%20;
    cout<<n<<" "<<k<<el;
    for(int i=1;i<=n;i++){
        a[i]=rand()%100;
        // cout<<a[i]<<" ";
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    srand(time(0));
    while(T--){
        solve();
    }
    return 0;
}