#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n;
ll tx,ty,tz;
ll a[N][N];
ll dx[]={1,0},dy[]={0,1};
void solve(){
    cin>>n;
    while(cin>>tx>>ty>>tz){
        if(tx==0&&ty==0&&tz==0) break;
        a[tx][ty]=tz;
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