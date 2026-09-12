#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m,q;
void solve(){
    cin>>n>>m>>q;
    while(q--){
        ll op,x;
        cin>>op>>x;
        if(op==1){
            n-=x;
            cout<<x*m<<el;
        }else{
            m-=x;
            cout<<n*x<<el;
        }
    }
    
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