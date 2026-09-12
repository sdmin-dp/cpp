#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
queue<ll> q;
void  dfs(){
    if(q.size()==n){
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        exit(0);
    }
    for(ll i=1;i<=q.front();i++){
        q.push(i);
    }
}
void solve(){
    cin>>n;
    ll x;cin>>x;
    q.push(x);
    dfs();
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