#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=20+5;
ll n,m,h;
ll q;
ll lx,ly,lz,rx,ry,rz;
ll ans[N][N][N];
void solve(){
    cin>>n>>m>>h;
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>lx>>ly>>lz>>rx>>ry>>rz;
        for(int a=lx;a<=rx;a++){
            for(int b=ly;b<=ry;b++){
                for(int c=lz;c<=rz;c++){
                    ans[a][b][c]=1;
                }
            }
        }
    }
    ll res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=h;k++){
                if(ans[i][j][k]==0) res++;
            }
        }
    }
    cout<<res;
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