#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;
void solve() {
    cin>>n;
    ll x=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<setw(2)<<setfill('0')<<x++;
        }
        cout<<'\n';
    }
    cout<<'\n';
    x=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(n-i)*2;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<setw(2)<<setfill('0')<<x++;
        }
        cout<<'\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}