#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const double b98=98.0/100.0;
double n;
double x=2.0;
void solve(){
    cin>>n;
    for(int i=1;;i++){
        if(n<=0){cout<<i-1;break;}
        n-=x;
        x*=b98;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}