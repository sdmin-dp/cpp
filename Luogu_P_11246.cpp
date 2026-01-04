#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;
bool vis[N];
ll dp[N];
vector<ll> v;
void solve(){
    cin>>n;
    for(int i=1;i*i<=n;i++){
        vis[i*i]=1;
        v.push_back(i*i);
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++){
        if(vis[i]==1) dp[i]=1;
        else{
            for(auto j:v){
                if(i<=j) break;
                dp[i]=min(dp[i],dp[i-j]+1);
            }
        }
    }
    cout<<dp[n];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}