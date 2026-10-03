#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
struct node{
    ll first,second;
    bool operator < (const node b) const{
        if(first!=b.first) return first<b.first;
        else return second<b.second;
    };
};
ll n;
priority_queue<node> q;
void solve(){
    cin>>n;
    ll gra=0,cnt=0,sum=0,b_sum=0;
    for(int i=1;i<=n;i++){
        ll w,r,p,g,c;
        cin>>w>>r>>p>>g>>c;
        sum+=g;gra=max(gra,p);
        while(sum>c){
            ll t=q.top().first;q.pop();
            sum-=t;b_sum-=t;cnt--;
        }
        if(gra>=r){
            if(sum+w<=c){
                cnt++;
                sum+=w;
                b_sum+=w;
                q.push({w,i});
            }else if(!q.empty()&&w<q.top().first&&sum-q.top().first+w<=c){
                ll t=q.top().first;q.pop();
                sum-=t;sum+=w;
                b_sum-=t;b_sum+=w;
                q.push({w,i});
            }
        }
    }
    cout<<cnt<<" "<<b_sum<<el;
    vector<ll> ans;
    while(!q.empty()) ans.push_back(q.top().second),q.pop();
    sort(ans.begin(),ans.end());
    for(auto i:ans) cout<<i<<" ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("specimen.in","r",stdin);
    freopen("specimen.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}