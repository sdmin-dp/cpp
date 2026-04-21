#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
vector<ll> v;
priority_queue<ll,vector<ll>,greater<ll>> q;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x,y;cin>>x>>y;
        if(x<=y){
            v.push_back(x);
            q.push(y-x);
        }
    }
    ll cnt=0;
    ll time=0;
    while(!q.empty()){
        ll x=q.top();
        q.pop();
        if(time<x){
            cnt++;
            
        }
    }
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