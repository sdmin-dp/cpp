#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
pair<ll,ll> a[N];
ll ans[N];
ll sumdan;//下m-1天蛋的费用，用于判断
ll sum;//统计后面提供的美味值
int kaoji[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for(int i=n;i>=1;i--){
        if(a[i].first>=0&&a[i].second>=0) ans[i]=max(m*a[i].first,(m-1)*a[i].first+a[i].second);
        if(a[i].first>=0&&a[i].second<0) ans[i]=m*a[i].first;
        if(a[i].first<0&&a[i].second>=0) ans[i]=a[i].second;
        else{
            if(-min(a[i].first*m,a[i].second)>sum){
                sum=0;
                n=i-1;
            }else if(min(a[i].first,a[i].second)<-(m-1)*sumdan){
                
            }
        }
    }
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