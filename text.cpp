#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
void solve(){
    ll n;
    cin>>n;
    for(int i=2;i<=n;i++){
        if(n%i!=0) continue;
        for(int j=i+1;j<=n;j++){
            if(n%(i*j)==0){
                ll k=n/(i*j);
                if(k==1) continue;
                if(i!=j&&j!=k&&i!=k){
                    cout<<i<<" "<<j<<" "<<k<<el;
                    return;
                }
            }
        }
    }
    cout<<"NO";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}