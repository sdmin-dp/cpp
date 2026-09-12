#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
struct node{
    ll to,next;
}e[N]; 
ll h[N],in[N];
ll cnt=0;
ll n;
bool vis[N];
stack<ll> st;
void add(ll u,ll v){
    ++cnt;
    e[cnt].to=v;
    e[cnt].next=h[u];
    h[u]=cnt;
}
void tpsort(ll idx){
    if(vis[idx]) return;
    vis[idx]=1;
    for(int i=h[idx];i;i=e[i].next){
        tpsort(e[i].to);
    }
    st.push(idx);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        while(1){
            ll x;
            cin>>x;
            if(!x) break;
            add(i,x);
        }
    }
    for(int i=1;i<=n;i++){
        tpsort(i);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}