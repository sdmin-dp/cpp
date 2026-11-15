#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
void solve(){
    cin>>n;
    bool flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==9)flag=1;
    }
    if(!flag){
        cout<<-1;
        return;
    }
    sort(a+1,a+n+1);
    cout<<a[1];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}