#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
ll n,m;
string s;
string ans;
unordered_map<ll,char> mp;
ll N;
void solve(){
    mp.insert({0,'0'});
    mp.insert({1,'1'});
    mp.insert({2,'2'});
    mp.insert({3,'3'}); 
    mp.insert({4,'4'});
    mp.insert({5,'5'});
    mp.insert({6,'6'});
    mp.insert({7,'7'});
    mp.insert({8,'8'});
    mp.insert({9,'9'});
    mp.insert({10,'A'});
    mp.insert({11,'B'});
    mp.insert({12,'C'});
    mp.insert({13,'D'});
    mp.insert({14,'E'});
    mp.insert({15,'F'});
    mp.insert({16,'G'});
    mp.insert({17,'H'});
    mp.insert({18,'I'});
    mp.insert({19,'J'});
    mp.insert({20,'K'});
    mp.insert({21,'L'});
    // for(auto i:mp){
    //     cout<<i.first<<" "<<i.second<<el;
    // }
    cin>>n>>m;
    N=n;
    while(n){
        ll k=n%m;
        ll q=n/m;
        if(k<0){
            k-=m;
            q++;
        }
        ans+=mp[k];
        n=q;
    }
    reverse(ans.begin(),ans.end());
    cout<<N<<"="<<ans<<"(base"<<m<<")";
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