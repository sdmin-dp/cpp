#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2000+5;
ll n;
ll a[N];
ll l[N][N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        ll c=0;
        for(int k=n;k>j;k--){
            if(a[k]>a[j]) c++;
            l[j][k-1]=c;
        }
    }
    ll ans=0;
    for(int k=3;k<n;k++){
        ll c=0;
        for(int j=1;j<k;j++){
            if(a[j]<a[k]){
                c++;
            }
            else if(a[k]<a[j]){
                ans+=c*l[j][k];
            }
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("four.in","r",stdin);
    freopen("four.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}