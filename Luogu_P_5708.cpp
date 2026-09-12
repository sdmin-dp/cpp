#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
double a,b,c;
double p;
void solve(){
    cin>>a>>b>>c;
    p=(a*1.0+b*1.0+c*1.0)/2.0;
    printf("%.1f",sqrt(p*(p-a)*(p-b)*(p-c)));
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