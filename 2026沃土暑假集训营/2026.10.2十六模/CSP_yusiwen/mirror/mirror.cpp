#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,k;
string s,t;
void solve(){
    cin>>n>>k;cin>>t;
    s=t;
    reverse(t.begin(),t.end());
    ll cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i]) cnt++;
    }
    if(k<cnt){
        cout<<-1;
        return;
    }
    k-=cnt;
    for(int i=0;i<n;i++){
        if(s[i]==t[i]&&k>=2){
            k-=2;
            s[i]='9',s[n-i-1]='9';
        }
        else if(s[i]!=t[i]&&k>=1){
            k--;
            s[i]='9',s[n-i-1]='9';
        }
    }
    cout<<s;
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