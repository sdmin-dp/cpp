#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
vector<ll> prime(ll n){
    vector<ll> ans;
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            ans.push_back(i);
            n/=i;
        }
    }
    if(n!=1) ans.push_back(n);
    return ans;
}
void solve(){
    ll n;cin>>n;
    vector<ll> ans=prime(n);
    if(ans.size()<3){
        cout<<"NO"<<el;
        return;
    }
    ll a=ans[0];
    ll b=1,c=1;
    ll cur=1;
    for(ll &i=cur;i<ans.size();i++){
        if(b>=2&&b!=a) break;
        else b*=ans[i];
    }
    for(ll &i=cur;i<ans.size();i++){
        c*=ans[i];
    }
    if(a==b||b==c||a==c){
        cout<<"NO"<<el;
        return;
    }
    if(a==1||b==1||c==1){
        cout<<"NO"<<el;
        return;
    }
    cout<<"YES"<<el;
    cout<<a<<" "<<b<<" "<<c<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}