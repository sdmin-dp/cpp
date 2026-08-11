#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
struct node{
    ll id,x,w;
};
bool cmp(node u,node v){
    return u.w<v.w;
}
bool cmp2(node u,node v){
    return u.x<v.x;
}
ll n,k;
node a[N];
void solve(){
    cin>>k>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].w;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    sort(a+1,a+2*k+1,cmp2);
    ll ans=0;
    for(int i=1;i<=2*k;i++){
        ans+=a[i].w;
    }
    cout<<ans<<el;
    ll i=1,j=2*k;
    for(;i<=j;i++,j--){
        cout<<a[i].id<<" "<<a[j].id<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("foldmap.in","r",stdin);
    freopen("foldmap.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}