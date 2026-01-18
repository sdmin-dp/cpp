#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e7+5;
string s,t;
ll n,m;
ll l=1,r;
ll z[N],p[N];
ll sum1,sum2;
//ll z[]={0,5,4,3,2,1},p[]={0,4,3,2,1,0,2,1};
void solve(){
    cin>>t>>s;
    s=' '+s;t=' '+t;
    n=s.size()-1,m=t.size()-1;
    for(int i=1;i<=n;i++){
        if(i>r){
            z[i]=0;
        }else{
            ll k=i-l+1;
            z[i]=min(z[k],r-i+1);
        }
        while(i+z[i]<=n&&z[i]+1<=n&&s[z[i]+1]==s[z[i]+i]) z[i]++;
        if(i+z[i]-1>r) l=i, r=i+z[i]-1;
    }
    l=1,r=0;
    for(int i=1;i<=m;i++){
        if(i>r){
            p[i]=0;
        }else{
            ll k=i-l+1; 
            p[i]=min(p[k],r-i+1);
        }
        while(i+p[i]<=m&&p[i]+1<=n&&s[p[i]+1]==t[p[i]+i]) p[i]++;
        if(i+p[i]-1>r) l=i, r=i+p[i]-1;
    }
    
    for(int i=1;i<=n;i++) sum1^=(i*(z[i]+1));
    cout<<sum1<<el;
    for(int i=1;i<=m;i++) sum2^=(i*(p[i]+1));
    cout<<sum2;
    for(int i=1;i<=n;i++) cerr<<z[i]<<" ";
    cerr<<el;
    for(int i=1;i<=m;i++) cerr<<p[i]<<" ";
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