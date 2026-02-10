#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
// bool flag[N];
// ll cnt;
// void dfs(ll x){
//     if(x==n+1){
//         bool f=1;
//         for(int i=1;i<=n;i++){
//             if(a[i]==i){
//                 f=0;
//                 break;
//             }
//         }
//         if(f) cnt++;
//         return;
//     }
//     for(int i=1;i<=n;i++){
//         if(!flag[i]){
//             flag[i]=1;
//             a[x]=i;
//             dfs(x+1);
//             flag[i]=0;
//             a[x]=0;
//         }
//     }
// }
void solve(){
    cin>>n;
    // dfs(1);
    // cout<<cnt;
    a[1]=0;
    a[2]=1;
    for(int i=3;i<=n;i++){
        a[i]=(i-1)*(a[i-1]+a[i-2]);
    }
    cout<<a[n];
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