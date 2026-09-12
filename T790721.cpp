#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n,m;
ll a[N][N],b[N][N],c[N][N],d[N][N];
char ch;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    cin>>ch;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            b[i][j]=a[i][j]*a[i+1][j+1]-a[i][j+1]*a[i+1][j];
        }
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            c[i][j]=b[i][j]*b[i+1][j+1]-b[i][j+1]*b[i+1][j];
        }
    }
    for(int i=1;i<n-2;i++){
        for(int j=1;j<m-2;j++){
            d[i][j]=c[i][j]*c[i+1][j+1]-c[i][j+1]*c[i+1][j];
        }
    }
    if(ch=='A'){
        cout<<n<<" "<<m<<el;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<el;
        }
    }else if(ch=='B'){
        cout<<n-1<<" "<<m-1<<el;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                cout<<b[i][j]<<" ";
            }
            cout<<el;
        }
    }else if(ch=='C'){
        cout<<n-2<<" "<<m-2<<el;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                cout<<c[i][j]<<" ";
            }
            cout<<el;
        }
    }else{
        cout<<n-3<<" "<<m-3<<el;
         for(int i=1;i<n-2;i++){
            for(int j=1;j<m-2;j++){
                cout<<d[i][j]<<" ";
            }
            cout<<el;
        }
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