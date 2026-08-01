#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n;
ll a[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(a[i]!=a[j]&&a[j]!=a[k]&&a[i]!=a[k]&&a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[k]+a[j]>a[i]){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
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