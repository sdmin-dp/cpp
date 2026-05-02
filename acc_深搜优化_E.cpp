#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n;
char a[N][N];
bool vis[N][N];
void IF(ll x,ll y){
    if(x>6){
        if(a[x][y]=='y'&&a[x-1][y]=='i'&&a[x-2][y]=='z'&&a[x-3][y]=='h'&&a[x-4][y]=='o'&&a[x-5][y]=='n'&&a[x-6][y]=='g'){
            vis[x][y]=vis[x-1][y]=vis[x-2][y]=vis[x-3][y]=vis[x-4][y]=vis[x-5][y]=vis[x-6][y]=1;
        }
    }
    if(x+6<=n){
        if(a[x][y]=='y'&&a[x+1][y]=='i'&&a[x+2][y]=='z'&&a[x+3][y]=='h'&&a[x+4][y]=='o'&&a[x+5][y]=='n'&&a[x+6][y]=='g'){
            vis[x][y]=vis[x+1][y]=vis[x+2][y]=vis[x+3][y]=vis[x+4][y]=vis[x+5][y]=vis[x+6][y]=1;
        }
    }
    if(y>6){
        if(a[x][y]=='y'&&a[x][y-1]=='i'&&a[x][y-2]=='z'&&a[x][y-3]=='h'&&a[x][y-4]=='o'&&a[x][y-5]=='n'&&a[x][y-6]=='g'){
            vis[x][y]=vis[x][y-1]=vis[x][y-2]=vis[x][y-3]=vis[x][y-4]=vis[x][y-5]=vis[x][y-6]=1;
        }
    }
    if(y+6<=n){
        if(a[x][y]=='y'&&a[x][y+1]=='i'&&a[x][y+2]=='z'&&a[x][y+3]=='h'&&a[x][y+4]=='o'&&a[x][y+5]=='n'&&a[x][y+6]=='g'){
            vis[x][y]=vis[x][y+1]=vis[x][y+2]=vis[x][y+3]=vis[x][y+4]=vis[x][y+5]=vis[x][y+6]=1;
        }
    }
    if(x>6&&y>6){
        if(a[x][y]=='y'&&a[x-1][y-1]=='i'&&a[x-2][y-2]=='z'&&a[x-3][y-3]=='h'&&a[x-4][y-4]=='o'&&a[x-5][y-5]=='n'&&a[x-6][y-6]=='g'){
            vis[x][y]=vis[x-1][y-1]=vis[x-2][y-2]=vis[x-3][y-3]=vis[x-4][y-4]=vis[x-5][y-5]=vis[x-6][y-6]=1;
        }
    }
    if(x>6&&y+6<=n){
        if(a[x][y]=='y'&&a[x-1][y+1]=='i'&&a[x-2][y+2]=='z'&&a[x-3][y+3]=='h'&&a[x-4][y+4]=='o'&&a[x-5][y+5]=='n'&&a[x-6][y+6]=='g'){
            vis[x][y]=vis[x-1][y+1]=vis[x-2][y+2]=vis[x-3][y+3]=vis[x-4][y+4]=vis[x-5][y+5]=vis[x-6][y+6]=1;
        }
    }
    if(x+6<=n&&y>6){
        if(a[x][y]=='y'&&a[x+1][y-1]=='i'&&a[x+2][y-2]=='z'&&a[x+3][y-3]=='h'&&a[x+4][y-4]=='o'&&a[x+5][y-5]=='n'&&a[x+6][y-6]=='g'){
            vis[x][y]=vis[x+1][y-1]=vis[x+2][y-2]=vis[x+3][y-3]=vis[x+4][y-4]=vis[x+5][y-5]=vis[x+6][y-6]=1;
        }
    }
    if(x+6<=n&&y+6<=n){
        if(a[x][y]=='y'&&a[x+1][y+1]=='i'&&a[x+2][y+2]=='z'&&a[x+3][y+3]=='h'&&a[x+4][y+4]=='o'&&a[x+5][y+5]=='n'&&a[x+6][y+6]=='g'){
            vis[x][y]=vis[x+1][y+1]=vis[x+2][y+2]=vis[x+3][y+3]=vis[x+4][y+4]=vis[x+5][y+5]=vis[x+6][y+6]=1;
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            IF(i,j);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j]) cout<<a[i][j];
            else cout<<'*';
        }
        cout<<el;
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