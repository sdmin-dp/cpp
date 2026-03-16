#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll c,p,s,n;
ll a[4][N];
ll ans;
void solve(){
    cin>>c>>p>>s>>n;
    ans=c*p*s;
    for(int i=1;i<=n;i++){
        string st;
        ll x,y;
        cin>>st;
        cin>>x>>y;
        if(st=="CP"){
            a[1][x]++;
            a[2][y]++;
            ans-=s;
        }else{
            a[2][x]++;
            a[3][y]++;
            ans-=c;
        }
    }
    for(int i=1;i<=c;i++) if(a[1][i]!=0) ans+=a[1][i]-1;
    for(int i=1;i<=p;i++) if(a[2][i]!=0) ans+=a[2][i]-1;
    for(int i=1;i<=s;i++) if(a[3][i]!=0) ans+=a[3][i]-1;
    cout<<ans;
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