#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
string s;
ll q[N],l[N];
void solve(){
    cin>>n;
    cin>>s;
    s=' '+s;
    ll sumq=0,suml=0;
    // cerr<<"左边的q:";
    for(int i=1;i<=n;i++){
        if(s[i]!='Q') suml++;
        else q[i]=suml;
        q[i]+=q[i-1];
        // cerr<<q[i]<<" ";
    }
    // cerr<<el;
    // cerr<<"右边的l:";
    for(int i=n;i>=1;i--){
        if(s[i]!='L') sumq++;
        else l[i]=sumq;
        l[i]+=l[i+1];
        // cerr<<l[i]<<" ";
    }
    suml=0;
    ll ans=0;
    for(int i=1;i<=n+1;i++){
        // cerr<<suml<<" "<<sumq<<el;
        ans=max(ans,suml*sumq+q[i-1]+l[i]);
        if(s[i]!='Q') suml++;
        if(s[i]!='L') sumq--;
    }
    cout<<ans;
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