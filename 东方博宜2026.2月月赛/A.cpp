#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,q;
ll a[N];
ll sum1[N],sum2[N],sum3[N];
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) sum1[i]=sum1[i-1]+1;
        else if(a[i]==2) sum2[i]=sum2[i-1]+1;
        else if(a[i]==3) sum3[i]=sum3[i-1]+1;
    }
    for(int i=1;i<=q;i++){
        
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