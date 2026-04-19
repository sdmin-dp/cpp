#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll ctoll(char c){
    return (c-'a'+1);
}
void tpsort(ll n){
    for(int i=1;i<=n;i++){
        
    }
}
ll n;
ll in[N];
string s,last;
vector<ll> g[N];
void solve(){
    cin>>n;
    cin>>last;
    for(int i=2;i<=n;i++){
        cin>>s;
        if(s<last){
            cout<<0;
            return;
        }
        for(ll i=0;i<last.size();i++){
            if(s[i]>last[i]){
                g[ctoll(last[i])].push_back(ctoll(s[i]));
                in[ctoll(s[i])]++;
            }
        }
        last=s;
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