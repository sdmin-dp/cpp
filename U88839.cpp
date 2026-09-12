#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
// ll dp[N];
ll last1=1,last2=2,last3=4,tmp;
void solve(){
    cin>>n;
    if(n==1){
        cout<<last1;
        return;
    }else if(n==2){
        cout<<last2;
        return;
    }else if(n==3){
        cout<<last3;
        return;
    }
    for(int i=4;i<=n;i++){
        tmp=last1+last2+last3;
        last1=last2;
        last2=last3;
        last3=tmp;
        // cerr<<tmp<<" ";
    }
    cout<<tmp;
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