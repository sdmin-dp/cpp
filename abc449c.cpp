#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,l,r;
string s;
//l<=j-i<=r
vector<ll> v[27];
ll cnt=1;
void solve(){
    cin>>n>>l>>r;
    cin>>s;
    for(int i=0;i<n;i++) v[s[i]-'a'+1].push_back(i);
    for(int i=1;i<=26;i++) sort(v[i].begin(),v[i].end(),greater<ll>());
    for(int i=0;i<n;i++){
        for(auto j:v[s[i]-'a'+1]){
            if(j<i||j-i<l) break;
            cnt++;
        } 
    }
    cout<<cnt;
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