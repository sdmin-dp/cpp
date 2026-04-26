#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,k,sum,cnt,p1,p2;
pair<ll,ll> a[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
unordered_map<ll,ll> mp;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    return x.second>y.second;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        p1=a[i].first,p2=a[i].second;
        if(mp.find(p1)==mp.end()&&cnt<k){
            mp[p1]++;
            q.push({p2,p1});
            cnt++;
            a[i].second=0;
        }
    }
    for(int i=1;i<=n;i++){
        p1=a[i].first,p2=a[i].second;
        if(p2==0) continue;
        if(cnt<k){
            mp[p1]++;
            q.push({p2,p1});
            cnt++;
            a[i].second=0;
        }else{
            if(mp.find(p1)==mp.end()) continue;
            ll q2=q.top().first,q1=q.top().second,s=mp.size();
            if(mp[q1]==1){
                if(p2+(s-1)*(s-1)>q2+s*s){
                    q.pop();
                    mp[q1]--;
                    mp[p1]++;
                    mp.erase(mp.find(q1));
                    q.push({p2,p1});
                }
            }
        }
    }
    sum=mp.size()*mp.size();
    while(!q.empty()){
        sum+=q.top().first;
        q.pop();
    }
    cout<<sum;
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