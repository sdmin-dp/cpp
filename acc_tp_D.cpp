#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
struct PPT{
    ll x1,x2,y1,y2;
}ppt[N];
struct point{
    ll x,y;
}p[N];

ll in[N],res[30];
bool check(ll i,ll j){
    if(p[j].x<ppt[i].x1) return 0;
    if(p[j].x>ppt[i].x2) return 0;
    if(p[j].y<ppt[i].y1) return 0;
    if(p[j].y>ppt[i].y2) return 0;
    return 1;
}

void topsort(){
    queue<ll> q;
    for(int i=n+1;i<=2*n;i++){
        if(in[i]==1){
            q.push(i);
        }
    }
    while(!q.empty()){
        ll t=q.front();
        q.pop();
        ll tar=0;
        for(int i=1;i<=n;i++){
            if(!res[i]&&check(i,t-n)){
                tar=i;
                break;
            }
        }
        res[tar]=t-n;
        for(int i=1;i<=n;i++){
            if(check(tar,i)){
                if(--in[i+n]==1){
                    q.push(i+n);
                }
            }
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ppt[i].x1>>ppt[i].x2>>ppt[i].y1>>ppt[i].y2;
    }
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
        for(int j=1;j<=n;j++){
            if(check(j,i)){
                in[i+n]++;
            }
        }
    }
    topsort();
    int cnt = 0;
    for (int i=1;i<=n;i++) if(res[i]) cnt++;
    if(cnt<n){
        cout<<"None";
        return;
    }
    for(int i=1;i<=n;i++){
        cout<<char(i+'A'-1)<<" "<<res[i]<<el;
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