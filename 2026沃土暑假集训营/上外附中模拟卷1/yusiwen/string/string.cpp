#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
string s;
unordered_set<string> st;
void dfs(string t,ll x,ll k,ll last){
    // cerr<<last<<" "<<x<<el;
    // cerr<<t<<el;
    if(k==m&&t.size()==s.size()&&x==n){
        // cerr<<t<<el;
        st.insert(t);
    }
    if(x==n) return;
    dfs(t,x+1,k,last);
    // if(last>x) return;
    string ss=s.substr(last+1,x-last);
    dfs(ss+t,x+1,k+1,x);
    dfs(t+ss,x+1,k+1,x);
}
void solve(){
    cin>>n>>m>>s;
    dfs("",0,0,-1);
    // for(auto i:st) cerr<<i<<el;
    cout<<st.size();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}