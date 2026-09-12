#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
deque<pair<ll,ll>> dq;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll op;
        cin>>op;
        if(op==1){
            ll x,num;
            cin>>x>>num;
            dq.push_back({num,x});
        }else{
            ll num,ans=0;
            cin>>num;
            while(num>0){
                auto x=dq.front();
                dq.pop_front();
                if(x.first<=num){
                    num-=x.first;
                    ans+=x.first*x.second;
                }else{
                    ans+=num*x.second;
                    x.first-=num;
                    num=0;
                    dq.push_front(x);
                }
            }
            cout<<ans<<el;
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