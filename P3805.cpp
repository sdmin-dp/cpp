#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s,t;
string manacher(){
    if(s.empty()) return "";
    t='#';
    for(char c:s) t+=c,t+='#';
    ll m=0,r=0,n=t.size();
    ll maxlen=0,maxcenter=0;
    vector<ll> p(n,0);
    for(int i=0;i<n;i++){
        ll k=2*m-i;
        if(i<r) p[i]=min(r-i,p[k]);
        int left=i-(1+p[i]),right=i+(1+p[i]);
        while(left>=0&&right<n&&t[left]==t[right]){
            p[i]++;
            left--;
            right++;
        }
        if(i+p[i]>r){
            m=i,r=i+p[i];
        }
        if(p[i]>maxlen){
            maxlen=p[i],maxcenter=i;
        }
    }
    ll b=(maxcenter-maxlen)/2;
    return s.substr(b,maxlen);
}
void solve(){
    cin>>s;
    cout<<manacher().size();
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