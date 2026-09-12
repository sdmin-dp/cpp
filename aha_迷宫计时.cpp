#include<bits/stdc++.h>
using namespace std;
#define ll int
#define el '\n'
const ll N=7+3;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll n,m,t;
char a[N][N];
bool vis[N][N];
ll bx,by,ex,ey;
bool dfs(ll x,ll y,ll step){
    if(step>t) return 0;
    ll dis=abs(x-ex)+abs(y-ey);
    ll shenyu=t-step;
    if(dis>shenyu||abs(dis-shenyu)%2!=0) return 0;
    if(x==ex&&y==ey){
        if(step==t) return 1;
        else return 0;
    }
    for(int i=0;i<4;i++){
        ll xx=x+dx[i],yy=y+dy[i];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]&&a[xx][yy]!='X'){
            vis[xx][yy]=1;
            if(dfs(xx,yy,step+1)) return 1;
            vis[xx][yy]=0;
        }
    }
    return 0;
}
void solve(){
    while(scanf("%d%d%d",&n,&m,&t)==3&&(n!=0||m!=0||t!=0)){
        // printf("%d %d %d",n,m,t);
        memset(vis,0,sizeof vis);
        if(n==0&&m==0&&t==0) return;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='S') bx=i,by=j;
                if(a[i][j]=='D') ex=i,ey=j;
            }
        }
        vis[bx][by]=1;
        if(abs(bx-ex)+abs(by-ey)>t){
            // cout<<"NO"<<el;
            printf("NO\n");
            continue;
        }
        
        if(dfs(bx,by,0)) printf("YES\n");
        else printf("NO\n");
    }
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

/*
4 4 6
S...
....
....
...D
*/
