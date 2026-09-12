#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;

void solve(){
    ll a[3],n;
    cin>>a[0]>>a[1]>>a[2]>>n;
    sort(a,a+3);
    ll d1=a[2]-a[1],d2=a[2]-a[0];
    // cerr<<d1<<" "<<d2<<el;
    n-=d1;n-=d2;
    if(n>=0&&n%3==0) cout<<"YES"<<el;
    else cout<<"NO"<<el;    
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