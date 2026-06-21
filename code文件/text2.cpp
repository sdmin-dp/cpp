#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e6+5;
set<ll> st;
ll k=2,n=N;
void solve(){
    st.insert(1);
    st.insert(2);
    for(int i=1;i<=n;i++){
        if(st.find(i)!=st.end()) continue;
        cout<<i<<" "<<i+k<<"\n";
        st.insert(i);
        st.insert(i+k);
        k++;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    freopen("wywolff2.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}