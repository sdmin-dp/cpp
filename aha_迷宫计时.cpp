#include<bits/stdc++.h>
using namespace std;
#define ll int
#define el '\n'
const ll N=15+5;
struct node{
    ll x,y,step;
};
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll n,m,t;
char a[N][N];
bool vis[N][N];
ll bx,by,ex,ey;
bool flag=0;
void dfs(ll x,ll y,ll step){
    if(flag) return;
    ll dis=abs(x-ex)+abs(y-ey);
    ll shenyu=t-step;
    if(dis>shenyu||abs(dis-shenyu)%2!=0) return;
    if(x==ex&&y==ey&&step==t){
        flag=1;
        return;
    }
    for(int i=0;i<4;i++){
        ll xx=x+dx[i],yy=y+dy[i];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]&&a[xx][yy]!='X'){
            vis[xx][yy]=1;
            dfs(xx,yy,step+1);
            vis[xx][yy]=0;
        }
    }
}
void solve(){
    while(1){
        scanf("%d%d%d",&n,&m,&t);
        // printf("%d %d %d",n,m,t);
        memset(vis,0,sizeof vis);
        flag=0;
        if(n==0&&m==0&&t==0) return;
        
        for(int i=1;i<=n;i++){
            getchar();
            for(int j=1;j<=m;j++){
                scanf("%c",&a[i][j]);
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
        dfs(bx,by,0);
        if(flag) printf("YES\n");
        else printf("NO\n");
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

/*
4 4 6
S...
....
....
...D
*/