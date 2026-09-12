#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
// const ll N=1e5+5;
ll n;
set<ll> st;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll op,x;
        cin>>op>>x;
        if(op==1){
            st.insert(x);
        }else if(op==2){
            if(st.empty()) continue;
            auto pos=st.lower_bound(x);
            if(pos==st.end()||*pos!=x) continue;
            st.erase(st.lower_bound(x));
            // for(auto i:st) cerr<<i<<" ";
        }else{
            if(st.empty()){
                cout<<-1<<el;
                continue;
            }
            auto lpos=st.upper_bound(x); 
            lpos--;
            auto rpos=st.lower_bound(x);
            if(rpos==st.end()){
                cout<<*lpos<<el;
                continue;
            }
            ll l=*lpos,r=*rpos;
            if(abs(x-l)<=abs(x-r)) cout<<l<<el;
            else cout<<r<<el;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("marker.in","r",stdin);
    // freopen("marker.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}