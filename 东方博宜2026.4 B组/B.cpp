#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,k; 
pair<ll,ll> a[N];
ll inq[N];
bool vis[N];
ll cnt,sum;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].second>>a[i].first;
    }   
    sort(a+1,a+n+1,greater<pair<ll,ll>>());
    for(int i=1;i<=n;i++){
        if(!inq[a[i].second]&&sum<k){
            q.push({a[i].first,a[i].second});
            cnt++;
            sum++;
            inq[a[i].second]++;
            vis[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&sum<k){
            q.push({a[i].first,a[i].second});
            if(!inq[a[i].second]) cnt++;
            sum++;
            inq[a[i].second]++;
            vis[i]=1;
        }
    }   
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        auto top=q.top();
        if(inq[a[i].second]==1){
            ll tmp1=cnt*cnt,tmp2=(cnt-1)*(cnt-1);
            ll t=a[i].first-top.first-tmp1+tmp2;
            if(t>0){
                q.pop();
                q.push(a[i]);
            }
        }else{
            if(a[i].first>top.first){
                
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