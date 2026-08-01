#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const int MAX=1005;
int n,m;
int g[MAX][MAX];
int dist[MAX][MAX][2];
struct Node{
    int x,y,p;
};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            dist[i][j][0]=dist[i][j][1]=-1;
        }
    }
    queue<Node> q;
    int sp=0;
    if(g[1][1]==0){cout<<-1<<el;return;}
    if(g[1][1]==2)sp=1;
    if(g[1][1]==4)sp=0;
    if(g[1][1]==3&&sp==0){cout<<-1<<el;return;}
    dist[1][1][sp]=0;
    q.push({1,1,sp});
    while(!q.empty()){
        Node c=q.front();
        q.pop();
        if(c.x==n&&c.y==m){
            cout<<dist[c.x][c.y][c.p]<<el;
            return;
        }
        for(int i=0;i<4;i++){
            int nx=c.x+dx[i],ny=c.y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]==0)continue;
            int np=c.p,ns=dist[c.x][c.y][c.p]+1;
            if(g[nx][ny]==3&&np==0)continue;
            if(g[nx][ny]==2)np=1;
            if(g[nx][ny]==4){
                np=0;
                int tx=nx,ty=ny;
                while(true){
                    int ntx=tx+dx[i],nty=ty+dy[i];
                    if(ntx<1||ntx>n||nty<1||nty>m)break;
                    if(g[ntx][nty]==0||g[ntx][nty]==3)break;
                    tx=ntx;ty=nty;ns++;
                    if(g[tx][ty]!=4){
                        if(g[tx][ty]==2)np=1;
                        break;
                    }
                }
                nx=tx;ny=ty;
            }
            if(dist[nx][ny][np]==-1||dist[nx][ny][np]>ns){
                dist[nx][ny][np]=ns;
                q.push({nx,ny,np});
            }
        }
    }
    cout<<-1<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
