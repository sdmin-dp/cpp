#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,k;
string s,t;
bool ish[N];
void solve(){
    cin>>n>>k;cin>>t;
    s=t;
    reverse(t.begin(),t.end());
    // cerr<<s<<" "<<t<<el;
    ll cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i]) cnt++;
    }
    cnt/=2;
    if(k<cnt){
        cout<<-1;
        return;
    }
    k-=cnt;
    // cerr<<cnt;
    for(int i=1;i<=n;i++){
        if(s[i]!=t[i]){
            s[i]=s[n-i-1]=max(s[i],s[n-i-1]);
            ish[i]=ish[n-i-1]=1;
        }
    }
    // cerr<<k<<" "<<cnt;
    for(int i=0;i<n&&i<=n-i-1;i++){
        if(!ish[i]&&!ish[n-i-1]&&s[i]!='9'&&k>=2){
            k-=2;
            s[i]='9',s[n-i-1]='9';
            // cerr<<1<<" "<<i<<" "<<k<<el;
        }
        else if(ish[i]&&ish[n-i-1]&&s[i]!='9'&&k>=1){
            k--;
            s[i]='9',s[n-i-1]='9';
            // cerr<<2<<" "<<i<<" "<<k<<el;
        }else if(i==n-i-1&&s[i]!='9'&&k>=1){
            k--;
            s[i]='9';
        }
    }
    cout<<s;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("mirror.in","r",stdin);
    freopen("mirror.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}