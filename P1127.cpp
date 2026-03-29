#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll n;
vector<pair<ll,char>> g[N];
ll cnt1,cnt2,cnt3,start;
ll idx[N];
string s[N];
deque<ll> res;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+n+1);
    
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