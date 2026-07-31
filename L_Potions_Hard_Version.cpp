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
    ll last=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(last+a[i]>=0){
            cnt++;
            last+=a[i];
            q.push(a[i]);
        }else{
            if(q.empty()) continue;
            auto t=q.top();q.pop();
            cnt--;last-=t;
            if(t<a[i]){
                cnt++;
                last+=a[i];
                q.push(a[i]);
            }else{
                cnt++;
                last+=t;
                q.push(t);
            }
        }
    }
    cout<<cnt;
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