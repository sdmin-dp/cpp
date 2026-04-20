#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
pair<char,pair<ll,ll>> walk(char f,ll s,pair<ll,ll> x){
    char c;
    if(f=='U'){x.second+=s;c='R';}
    if(f=='D'){x.second-=s;c='L';}
    if(f=='L'){x.first-=s;c='U';}
    if(f=='R'){x.first+=s;c='D';}
    return {c,x};
}
void solve(){
    
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