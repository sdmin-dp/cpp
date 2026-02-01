#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s,t;
ll a[N],b[N];
bool c[N];
string jian(){
    string ans;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    for(int i=0;i<s.size();i++) a[i+1]=int(s[i]-48);
    for(int i=0;i<t.size();i++) b[i+1]=int(t[i]-48);
    for(int i=1;i<=s.size();i++){
        if(c[i]) a[i]--;
        ll k=a[i]-b[i];
        if(k<0){
            k+=10;
            cerr<<a[i]<<" "<<b[i]<<el;
            c[i+1]=1;
        }
        ans=ans+char(k+48);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
bool sxiaoyut(string &x,string &y){
    if(x.size()<y.size()) return 1;
    if(x.size()==y.size()&&x<y) return 1;
    else return 0;
}
void solve(){
    cin>>s>>t;
    bool flag=0;
    if(sxiaoyut(s,t)) flag=1;
    if(flag) swap(s,t);
    string res=jian();
    while(res[0]=='0'&&res.size()>1) res.erase(0,1); 
    if(flag) res='-'+res;
    cout<<res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}