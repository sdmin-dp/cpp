#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,a,b;
ll x;
ll v[3];
void solve(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>x;
        v[0]=a;v[1]=b;v[2]=x;
        sort(v,v+2+1);
        if(v[0]*v[1]==v[2]||v[0]+v[1]==v[2]){
            
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