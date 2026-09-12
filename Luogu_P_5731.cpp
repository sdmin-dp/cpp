#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e2+5;
ll n,a[N][N],x=1,y=1;
ll dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void solve(){
    cin>>n;
    ll fx=0;
    memset(a,0x3f,sizeof(a));
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=0;
    for(int i=1;i<=n*n;i++){
        a[x][y]=i;
        ll xx=x+dx[fx],yy=y+dx[fx];
        if(a[xx][yy]!=0){
            fx=(fx+1)%4;
        }
        x+=dx[fx],y+=dy[fx];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<setw(3)<<a[i][j];
        }
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}