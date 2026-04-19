#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
string s,last;
vector<ll> g[N];
void solve(){
    cin>>n;
    cin>>last;
    for(int i=2;i<=n;i++){
        cin>>s;
        if(s>last){
            cout<<0;
            return;
        }
        for(ll i=0;i<last.size();i++){
            if(s[i]>last[i]){
                
            }
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