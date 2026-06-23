#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll cnt1,cnt2;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bool flag;
            cin>>flag;
            if(flag){
                if(i==m) cnt1++;
                if(j==m) cnt2++;
            } 
        }
    }
    cout<<cnt1<<" "<<cnt2<<" "<<cnt1+cnt2;
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