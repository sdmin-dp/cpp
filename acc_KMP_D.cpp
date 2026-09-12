#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s;
ll k;
ll nxt[N];
ll cnt;
void solve(){
    cin>>s;
    cin>>k;ll n=s.size();
    while(s.size()>0){
        memset(nxt,0,sizeof(nxt));
        for(int i=1,j=0;i<s.size();i++){
            while(j>0&&s[i]!=s[j]) j=nxt[j-1];
            if(s[i]==s[j]) j++;
            nxt[i]=j;
            ll p=nxt[i]-1;
            while(p>=0&&2*(p+1)>=i+1){
                p=nxt[p]-1;
            }
            // cerr<<p<<el;
            if(p+1>=k&&2*(p+1)<=i){
                cnt++;
            }
        }
        // cout<<s<<":";
        // for(int i=0;i<s.size();i++) cout<<nxt[i]<<" ";
        // cout<<el;
        s.erase(0,1);
    }
    cout<<cnt;
}

int main() {
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