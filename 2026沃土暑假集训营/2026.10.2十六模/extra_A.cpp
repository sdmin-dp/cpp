#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,k,cnt;
string s,t;
bool ish[N];
void solve(){
    cin>>n>>k>>t;s=t;
    reverse(t.begin(),t.end());
    for(int i=0;i<=n-i-1;i++) if(s[i]!=t[i]) cnt++;
    if(k<cnt){
        cout<<-1;
        return;
    }
    k-=cnt;
    for(int i=1;i<=n;i++){
        if(s[i]!=t[i]){
            s[i]=s[n-i-1]=max(s[i],s[n-i-1]);
            ish[i]=ish[n-i-1]=1;
        }
    }
    for(int i=0;i<n&&i<=n-i-1;i++){
        if(!ish[i]&&!ish[n-i-1]&&s[i]!='9'&&k>=2){
            k-=2;
            s[i]='9',s[n-i-1]='9';
        }else if(ish[i]&&ish[n-i-1]&&s[i]!='9'&&k>=1){
            k--;
            s[i]='9',s[n-i-1]='9';
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
    // freopen("mirror.in","r",stdin);
    // freopen("mirror.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
5 1
91899
91999
*/