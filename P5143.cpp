#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e4+5;
struct node{
    double x,y,z;
};
bool cmp(node x,node y){
    return x.z<y.z;
}
ll n;
node a[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    sort(a+1,a+n+1,cmp);
    double ans=0.0;
    for(int i=2;i<=n;i++){
        ll xi=a[i].x,yi=a[i].y,zi=a[i].z;
        ll xj=a[i-1].x,yj=a[i-1].y,zj=a[i-1].z;
        ans+=sqrt((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj)+(zi-zj)*(zi-zj));
    }
    printf("%.3f",ans);
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