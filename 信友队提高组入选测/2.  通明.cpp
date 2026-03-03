#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const int N=5005;
int n,w,a[N],dp[N]; 
struct node{int id,val;}p[N];
bool cmp(node x,node y){
    if(x.val!=y.val)return x.val<y.val;
    return x.id<y.id;
}
void solve(){      
    cin>>n>>w;
    for(int i=1;i<=n;i++){ 
        p[i].id=i;
        cin>>p[i].val;
    }
    sort(p+1,p+n+1,cmp);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(p[j].val<p[i].val&&abs(p[i].id-p[j].id)<=w){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bright.in","r",stdin);
    freopen("bright.out","w",stdout);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}
