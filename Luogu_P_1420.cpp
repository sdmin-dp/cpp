#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+5;
ll n;
ll a[N];
ll cnt=1,mx;
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]+1){
            cnt++;
        }
        else{
            mx=max(mx,cnt);
            cnt=1;
        }
    }
    mx=max(mx,cnt);
    cout<<mx;
}
int main() {
    ios::sync_with_stdio(false);
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


























/*20
3 5 6 2 3 4 5 6 8 9 10 11 12 13 14 15 16 17 18 19*/