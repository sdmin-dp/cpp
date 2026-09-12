#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+5;
ll n;
ll a[N];
ll mx=-1e18,mn=1e18,sum=0;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
        sum+=a[i];
    }
    sum-=mn;
    sum-=mx;
    printf("%.2f",sum*1.0/((n-2)*1.0));
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