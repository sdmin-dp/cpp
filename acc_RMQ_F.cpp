#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=250+5;
const ll mxlog=8;
ll n,m,q;
ll a[N][N];
ll st[N][N][10][10];
void init(){
    for(int i=1;i<=n;i++) for(ll j=1;j<=m;j++) st[i][j][0][0]=a[i][j];
    for(int i=1;i<=n;i++){
        for(int k=1;k<=mxlog;k++){
            for(int j=1;j+(1<<k-1)-1<=m;j++){
                st[i][j][0][k]=max(st[i][j+(1<<k-1)-1][0][k-1],st[i][j][0][k-1]);
            }
        }
    }
    for(int  j=1;j<=m;j++){
        for(int k=1;k<=mxlog;k++){
            for(int i=1;i+(1<<k-1)-1<=n;i++){
                st[i][j][0][k]=max(st[i][j+(1<<k-1)-1][0][k-1],st[i][j][0][k-1]);
            }
        }
    }
    for(int k=1;k<=mxlog;k++){
        for(int l=1;l<=mxlog;l++){
            for(int i=1;i+(1<<k-1)-1<=n;i++){
                for(int j=1;j+(1<<l-1)-1<=m;j++){
                    st[i][j][k][l]=max({
                        st[i][j][n-1][m-1],
                        st[i][j+(1<<m-1)-1][n-1][m-1],
                        st[i+(1<<m-1)][j][n-1][m-1],
                        st[i+(1<<m-1)-1][j+(1<<m-1)-1][n-1][m-1]
                    });
                }
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    init();
    for(int i=1;i<=q;i++){
        cout<<query()<<el;
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