#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
void solve(){
    cin>>n>>m;
    for(int k=1;;k++){
        ll p=k;
        p=p*n+m;
        bool flag=1;
        for(int i=1;i<=n-1;i++){
            if(p%(n-1)==0){
                p=p/(n-1)+p+m;
            }else{
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<p;
            return;
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