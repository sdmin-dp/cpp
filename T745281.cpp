#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll n,m,x,y;
bool a[N][N];
ll cnt;
ll procnt;
void solve(){
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int j=1;j<=m;j++){
        cnt+=a[x][j];
    }
    for(int i=n;i>x;i--){
        for(int j=1;j<=m;j++){
            procnt+=a[i][j];
        }
    }
    cout<<procnt+1<<" "<<procnt+cnt;
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