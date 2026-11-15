#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N][3];
set<pair<ll,pair<ll,ll>>>st;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2];
        st.insert({a[i][1],{i,1}});
    }
    ll ans=0;
    while(1){
        auto t=*st.begin();
        st.erase(st.begin());
        if(m<t.first){
            cout<<ans;
            return;
        }
        ans++;
        m-=t.first;
        st.insert({a[t.second.first][3-t.second.second],{t.second.first,3-t.second.second}});
    }
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