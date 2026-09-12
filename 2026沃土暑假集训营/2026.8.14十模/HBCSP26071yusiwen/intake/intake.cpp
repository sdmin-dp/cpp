#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
ll a[N];
priority_queue<ll,vector<ll>,greater<ll>> q;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll sum=0,ans=0;
    for(int i=1;i<=n;i++){
        if(sum+a[i]>=0){
            sum+=a[i];
            q.push(a[i]);
            ans++;
        }else{
            if(q.empty()) continue;
            if(a[i]>q.top()){
                sum-=q.top();
                sum+=a[i];
                q.pop();
                q.push(a[i]);
            }
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("intake.in","r",stdin);
    freopen("intake.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}