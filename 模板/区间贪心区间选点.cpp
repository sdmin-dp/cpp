#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;

pair<ll,ll> a[N]; // first: 左端点, second: 右端点
ll n;

// 核心：优先按右端点从小到大排
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    if(x.second!=y.second) return x.second<y.second;
    return x.first<y.first;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    
    // 按右端点升序排序
    sort(a+1,a+n+1,cmp);
    
    ll ans=0;
    ll last=-2e18; // 记录上一次选点（扎针）的位置，初始设极小值
    
    for(int i=1;i<=n;i++){
        // 如果当前区间的左端点在上一针的右边，说明盖不住了
        if(a[i].first>last){
            ans++;
            last=a[i].second; // 贪心：直接扎在当前区间的右端点
        }
    }
    cout<<ans<<el;
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