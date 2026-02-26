#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e1+5;
ll r,k,n,m;
char a[N][N];
char ans[N*10][N*10];
void zhuan90(){
    char b[N][N];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll I=i,J=j;
            swap(I,J);
            J=n-J+1;
            b[I][J]=a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=b[i][j];
        }
    }
}
void solve(){
    cin>>r>>k>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=r/90;i++){
        zhuan90();
        swap(n,m);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cerr<<a[i][j];
        }
        cerr<<el;
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