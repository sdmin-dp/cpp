#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,k;
ll a[N];
bool flag=0;
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) flag=1;
    }
    if(flag){
        cout<<n<<el;
        return;
    }
    ll ans=0;
    if(k>0){
        ll i=1,j=0,mul=1;          // i 从 1 开始（1-based）
        while(i<=n&&j<n){
            while(mul<=k && j<n){
                ans=max(ans, j-i+1);
                mul*=a[++j];
            }
            while(mul>k && i<=n){
                mul/=a[i++];
            }
        }
        if(mul<=k) ans=max(ans, j-i+1);
    }
    cout<<ans<<el;                 // 移到 if 外面，k==0 也能输出 0
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);f
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
