#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m,k;
ll a[N],b[N];
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    sort(a+1,a+n+1,greater<ll>());
    sort(b+1,b+m+1,greater<ll>());
    ll i=1,j=1;
    while(i<=n&&j<=m){
        if(abs(a[i]-b[j])<=k){
            cout<<a[i]+b[j];
            return;
        }else if(a[i]>b[j]){
            i++;
        }else if(a[i]<b[j]){
            j++;
        }
    }
    cout<<-1;
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