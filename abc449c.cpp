#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n,l,r,cnt=0;
string s;
vector<ll> v[30];
void solve(){
    cin>>n>>l>>r>>s;
    for(int i=0;i<n;i++)v[s[i]-'a'+1].push_back(i);
    for(int i=0;i<n;i++){
        int id=s[i]-'a'+1;
        auto it1=lower_bound(v[id].begin(),v[id].end(),i+l);
        auto it2=upper_bound(v[id].begin(),v[id].end(),i+r);
        cnt+=distance(it1,it2);
    }
    cout<<cnt<<el;
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
