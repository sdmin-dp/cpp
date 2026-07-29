#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N],b[N];
void solve(){
    cin>>n;
    ll ans=0;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>m;
    for(int j=0;j<m;j++) cin>>b[j];
    sort(a,a+n,greater<ll>());
    sort(b,b+m,greater<ll>());
    for (int i=0,j=0;i<n&&j<m;){
        if(a[i]>b[j]){
            if (a[i]-1==b[j]){
                ans++;
                j++;
            }
            i++;
        }
        else if(a[i]==b[j]){
            ans++;
            i++;
            j++;
        }
        else{
            if(b[j]-1==a[i]){
                ans++;
                i++;
            }
            j++;
        }
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