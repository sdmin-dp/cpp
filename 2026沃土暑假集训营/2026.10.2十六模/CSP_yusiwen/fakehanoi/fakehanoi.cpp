#include<bits/stdc++.h>
using namespace std;
long long n,x,y,z;
long long dp[35][4][4];
long long dis[4][4];
long long cst[4][4];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("fakehanoi.in","r",stdin);
    freopen("fakehanoi.out","w",stdout);
    cin>>n>>dis[1][2]>>dis[2][3]>>dis[1][3];
    cst[1][2]=dis[1][2],cst[2][3]=dis[2][3],cst[1][3]=dis[1][3];
    dis[2][1]=dis[1][2],dis[3][2]=dis[2][3],dis[3][1]=dis[1][3];
    cst[2][1]=cst[1][2], cst[3][2]=cst[2][3], cst[3][1]=cst[1][3];
     for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            dis[i][j]=(i==j?0:dis[i][j]);
    for(int k=1;k<=3;k++)
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            dp[1][i][j]=dis[i][j];
    for(int m=2;m<=n;m++){
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                if(j==i) continue;
                int k=6-i-j;
                dp[m][i][j]=min(dp[m-1][i][k]+cst[i][j]+dp[m-1][k][j],dp[m-1][i][j]+cst[i][k]+dp[m-1][j][i]+cst[k][j]+dp[m-1][i][j]);
            }
        }
    }
    cout<<dp[n][1][3];
}