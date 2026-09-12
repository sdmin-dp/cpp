#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=800+5;
ll n,m,ans=1e12;
ll a[N][N];
vector<ll> sorted;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int x1=1;x1+m-1<=n;x1++){
        for(int y1=1;y1+m-1<=n;y1++){
            ll x2=x1+m-1,y2=y1+m-1;
            sorted.clear();
            for(int i=x1;i<=x2;i++){
                for(int j=y1;j<=y2;j++){
                    sorted.push_back(a[i][j]);
                }
            }
            sort(sorted.begin(),sorted.end());
            ll len=sorted.size();
            len/=2;
            if(sorted.size()%2==0) len--;
            ans=min(ans,sorted[len]);
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