#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+5;
struct node{ll w,v,o;};
ll n,m;
vector<node> a(1);
ll dp[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll V,W,O;
        cin>>V>>W>>O;
        if(O<=0){
            a.push_back({V,W,O});
        }
        else{
            for(int j=1;j<=O;j*=2){
                a.push_back({V*j,W*j,-1});
                O-=j;
            }
            if(O!=0) a.push_back({V*O,W*O,-1});
        }
    }
    for(int i=1;i<a.size();i++){
        if(a[i].o==-1){
            for(int j=m;j>=a[i].w;j--){
                dp[j]=max(dp[j],dp[j-a[i].w]+a[i].v);
            }
        }
        else{
            for(int j=a[i].w;j<=m;j++){
                dp[j]=max(dp[j],dp[j-a[i].w]+a[i].v);
            }
        }
    }
    cout<<dp[m];
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