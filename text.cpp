#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,k,s,ans;
void solve(){
    cin>>n>>k;
    char c,last;
    cin>>last;
    for(int i=2;i<=n;i++){
        cin>>c;
        if(c!=last){
            s++;
        }
        last=c;
    }
    ans=n-1-s+(s%2&&s/2<=k)+min(s/2,k)*2;
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