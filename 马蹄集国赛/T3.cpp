#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N],b[N];
ll sum=0,res=1;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        res*=a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        sum+=b[i];
    }
    if(res==1) cout<<1;
    else if(res==-1&&sum%2==1) cout<<-1;
    else cout<<1;
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