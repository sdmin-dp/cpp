#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,k;
ll suma,sumb;
ll cnta,cntb;
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        if(i%k==0){
            suma+=i;
            cnta++;
        }
        else{
            sumb+=i;
            cntb++;
        }
    }
    printf("%.1f %.1f",suma*1.0/cnta*1.0,sumb*1.0/cntb*1.0);
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