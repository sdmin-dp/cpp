#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,v[N],nxt[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        nxt[i]=i+1;
    }
    nxt[0]=1;
    nxt[n]=-1;
    ll x=2,y=99,p=0;
    for(int i=0;i<=x;i++) p=nxt[p];
    v[++n]=y;
    nxt[n]=nxt[p];
    nxt[p]=n;
    p=n;
    p=0;
    for(int i=0;i<n;i++){
        cout<<v[nxt[p]];
        p=nxt[p];
    }

}

int main() {
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