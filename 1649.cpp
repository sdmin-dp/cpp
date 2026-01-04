#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n,a[N];
ll sum,k;
void solve(){
    cin>>n;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        a[i]=(379*a[i-1]+131)%997;
    }
    k=a[1];
    for(int i=1;i<=n;i++){
        k=max(k,a[i]);
        sum+=k;
    }
    cout<<sum;
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