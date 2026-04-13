#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;

void solve(){
    string s;
    cin>>s;
    ll l=0;
    ll cnt[]={0,0,0,0};
    ll ans=1e18;
    for(int r=0;r<s.size();r++){
        cnt[r]++;
        while(cnt[l]>1){
            l++;
            cnt[l]--;
        }
        if(cnt[1]>=1&&cnt[2]>=1&&cnt[3]>=1) ans=min(ans,r-l+1);
    }
    if(ans==1e18) cout<<0;
    else cout<<ans<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}