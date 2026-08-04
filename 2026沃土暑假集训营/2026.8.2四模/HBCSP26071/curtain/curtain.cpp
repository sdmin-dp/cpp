//hao nan ya,zhen de bu hui xie le
//I won't AK!:(,shui rang ni ba ti chu na me nan de?
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e2+5;
ll n,k;
ll c[N],t[N]/*,t2[N]*/;
bool checkA(){
    for(int i=1;i<=k;i++) if(c[i]!=1) return 0;
    return 1;
}
// bool checkB(){
//     for(int i=1;i<=n;i++) t2[i]=t[i];
//     reverse(t+1,t+n+1);
//     for(int i=1;i<=n;i++) if(t2[i]!=t[i]) return 0;
//     return 1;
// }

void solve(){
    cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>t[i];
    if(checkA()){
        ll cnt=1;
        for(int i=2;i<=n;i++){
            if(t[i]!=t[i-1]) cnt++;
        }
        cout<<cnt;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("curtain.in","r",stdin);
    freopen("curtain.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}