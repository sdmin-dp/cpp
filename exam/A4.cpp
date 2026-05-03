#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
struct node{
    ll x,y,h;
};
ll n;
node a[N];
bool cmp(node x,node y){
    return x.h>y.h;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y>>a[i].h;
    sort(a+1,a+n+1,cmp);
    if(a[1].h==0) 
    for(int cx=0;cx<=100;cx++){
        for(int cy=0;cy<=100;cy++){

            ll h=a[1].h+abs(a[1].x-cx)+abs(a[1].y-cy);

            bool f=1;

            for(int i=2;i<=n;i++){
                ll k=abs(a[i].x-cx)+abs(a[i].y-cy);
                if(a[i].h==0){
                    continue;
                }else if(h!=a[i].h+k){
                    f=0;
                    break;
                }
            }
            // cerr<<cx<<" "<<cy<<" "<<h<<el;
            if(f){
                cout<<cx<<" "<<cy<<" "<<h;
                return;
            }
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