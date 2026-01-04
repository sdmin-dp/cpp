#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
double t;
ll n;
void solve(){
    cin>>t;
    cin>>n;
    ll res=n*2;
    double ans=t/(n*1.0);
    printf("%.3f\n%lld",ans,res);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}