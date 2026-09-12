#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
double res;
void solve(){
    cin>>n;
    ll a,b,c;
    a=min(150ll,n);
    b=min(400ll-150ll,max(n-150,0ll));
    c=max(0ll,n-400);
    res=a*0.4463+b*0.4663+c*0.5663;
    printf("%.1f",res);
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