#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e6;
const long double g=(1.0+sqrtl(5.0))/2.0;

void solve(){
    ll a,b;cin>>a>>b;
    // if(a==433494437&&b==701408733){
    //     cout<<1;
    //     return;
    // }
    if(a>b) swap(a,b); 
    ll k=b-a;
    cout<<(a==floor(g*(k*1.0))?"0":"1");
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    // freopen("wywolff.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}