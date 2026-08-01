#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
ll n;
ll a[N];
bool flag=1;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            flag=0;
            break;
        }
    }
    cout<<(flag?0:1);
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