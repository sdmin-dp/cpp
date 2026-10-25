#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1000+5;
ll n,m,k,l,d;
//a[i]表示第i~i+1排之间的通道的贡献
//b[i]表示第i~i+1列之间的通道的贡献
pair<ll,ll> a[N],b[N];
void solve(){
    cin>>n>>m>>k>>l>>d;
    for(int i=1;i<=d;i++){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2){
            b[min(y1,y2)].first++;
        }else if(y1==y2){
            a[min(x1,x2)].first++;
        }
    }
    for(int i=1;i<m;i++) b[i].second=i;
    for(int i=1;i<n;i++) a[i].second=i;
    sort(b+1,b+m,greater<pair<ll,ll>>());
    sort(a+1,a+n,greater<pair<ll,ll>>());
    vector<ll> ansa,ansb;
    for(int i=1;i<=k;i++) ansa.push_back(a[i].second);
    for(int i=1;i<=l;i++) ansb.push_back(b[i].second);
    sort(ansa.begin(),ansa.end());
    sort(ansb.begin(),ansb.end());
    for(auto &i:ansa) cout<<i<<" ";
    cout<<el;
    for(auto &i:ansb) cout<<i<<" ";
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}