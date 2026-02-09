#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll h1,m1,h2,m2;
void solve(){
    cin>>h1>>m1>>h2>>m2;
    if(m2<m1){
        h2--;
        m2+=60;
    }
    
    cout<<(h2-h1)*60+m2-m1<<el;
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