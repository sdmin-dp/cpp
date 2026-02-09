#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll h,m,s,k;
void solve(){
    cin>>h>>m>>s>>k;
    s+=k;
    if(s>=60){
        m+=s/60;
        s%=60;
    }
    if(m>=60){
        h+=m/60;
        m%=60;
    }
    cout<<h<<" "<<m<<" "<<s;
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