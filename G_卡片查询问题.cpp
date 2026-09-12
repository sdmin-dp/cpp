#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N =2e5+5;
ll n,q;
vector<set<ll>> num(N);
void solve(){
    cin>>n>>q;
    vector<multiset<ll>> box(n+1);
    while(q--){
        ll op;
        cin>>op;
        if(op==1){
            ll i,j;
            cin>>i>>j;
            box[j].insert(i);
            num[i].insert(j);
        }else if(op==2){
            ll i;
            cin>>i;
            for(auto x:box[i]) cout<<x<<" ";
            cout<<el;
        }else if(op==3){
            ll i;cin>>i;
            for(auto x:num[i]) cout<<x<<" ";
            cout<<el;
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