#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll a[N];
ll n;
void Sort(){
    ll i=1,k=1,j=n;
    while(k<=j){
        if(a[k]==0) swap(a[k++],a[i++]);
        else if(a[k]==1) k++;
        else swap(a[k],a[j--]);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    Sort();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("kxxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}