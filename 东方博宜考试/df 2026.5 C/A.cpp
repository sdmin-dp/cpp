#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=20+5;
ll n,x;
ll a[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
bool flag[N];
void solve(){
    cin>>n;
    ll id1=0,id2=0;
    for(int i=n;i>=1;i--){
        cin>>x;
        ll cnt=0;
        flag[x]=1;
        for(int i=1;i<x;i++) if(!flag[i]) cnt++;
        id1+=cnt*a[i-1];
    }
    memset(flag,0,sizeof flag);
    for(int i=n;i>=1;i--){
        cin>>x;
        ll cnt=0;
        flag[x]=1;
        for(int i=1;i<x;i++) if(!flag[i]) cnt++;
        id2+=cnt*a[i-1];
    }
    cout<<abs(id1-id2);
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