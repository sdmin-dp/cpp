#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=15+5;
string s;
ll n;
bool dis[N][N];
ll t[N];
void print(__int128 num) {
    if(num>9){
        print(num/10);
    }
    putchar(num%10+'0');
}
void solve(){
    cin>>s>>n;
    for(int i=1;i<=n;i++){
        ll u,v;
        cin>>u>>v;
        dis[u][v]=1;
    }
    for(int i=0;i<=9;i++){
        dis[i][i]=1;
    }
    for(int k=1;k<=9;k++){
        for(int i=0;i<=9;i++){
            for(int j=1;j<=9;j++){
                dis[i][j]=dis[i][j]||(dis[i][k]&&dis[k][j]);
            }
        }
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(dis[i][j]) t[i]++;
        }
    }
    __int128 ans=1;
    for(int i=0;i<s.size();i++){
        ans*=t[s[i]-'0'];   
    }
    print(ans);
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