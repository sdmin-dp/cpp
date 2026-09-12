#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
ll n,m;
pair<ll,ll> a[N];
string dp[N];
ll mp[10]={0,2,5,5,4,5,6,3,7,6};
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    return x.first>y.first;
}
string maxx(string s,string t){
    if(s.size()<t.size()) return t;
    else if(s.size()>t.size()) return s;
    else return max(s,t);
}
void solve(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=mp[a[i].first];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=a[i].second;j<=m;j++){
            if(dp[j-a[i].second].size()==0&&j-a[i].second!=0) continue;
            dp[j]=maxx(dp[j],dp[j-a[i].second]+char(a[i].first+'0'));

            //cout<<j<<" "<<dp[j]<<'\n';
        }
    }
    // cout<<dp[0]<<'\n';
    // dp[0]+="c";
    // cout<<dp[0]<<'\n';
    // cout<<"!";
    cout<<dp[m]; 
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