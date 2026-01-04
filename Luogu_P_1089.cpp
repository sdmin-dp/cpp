#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll a[13];
ll n,sum;
void solve(){
    for(int i=1;i<=12;i++) cin>>a[i];
    for(int i=1;i<=12;i++){
        n+=300;
        if(n<a[i]){
            cout<<-i;
            return;
        }
        n-=a[i];
        sum+=(n/100)*100;
        n%=100;
    }
    cout<<sum+sum*20/100+n;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}