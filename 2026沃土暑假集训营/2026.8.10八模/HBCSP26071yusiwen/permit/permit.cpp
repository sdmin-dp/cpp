#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2500+5;
struct node{
    ll c,d,p;
};
ll n,m;
node a[N];
bool checkB(){
    for(int i=1;i<=n;i++){
        if(a[i].d!=0){
            return 0;
        }
    }
    return 1;
}
bool cmp(node x,node y){
    return x.c<y.c;
}
void solve(){
    cin>>n>>m;
    cin>>a[1].c>>a[1].p;
    for(int i=2;i<=n;i++){
        cin>>a[i].c>>a[i].d>>a[i].p;
    }
    if(checkB()){
        sort(a+1,a+n+1,cmp);
        ll ans=0,sum=0;
        for(int i=1;i<=n;i++){
            if(sum+a[i].c<=m){
                sum+=a[i].c;
                ans++;
            }
        }
        cout<<ans;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("permit.in","r",stdin);
    freopen("permit.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}