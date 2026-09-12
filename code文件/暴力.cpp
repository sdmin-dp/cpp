#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
vector<ll> a,b;
vector<ll> c;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        c.push_back(i);
        ll x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        b.push_back(x);
    }
    ll id1=0,id2=0;
    ll cnt=0;
    do{
        cnt++;
        if(c==a) id1=cnt;
        if(c==b) id2=cnt;
    }while(next_permutation(c.begin(),c.end()));
    cout<<abs(id1-id2);
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