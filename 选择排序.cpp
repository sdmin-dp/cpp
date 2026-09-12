#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll a[N]={7,5,3,9,8,6,4,2},n=9;
ll cnt=0;
void solve(){
    for(int i=0;i<n-1;i++){
        ll k=i;
        for(int j=i+1;j<n;j++){
            if(a[k]>a[j]) k=j;
        }
        if(k!=i) swap(a[k],a[i]),cnt++;
    }
    cout<<cnt;
}

int main() {
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