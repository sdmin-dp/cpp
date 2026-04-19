#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string ans;
void solve(){
    ll n=rand()%10;
    ll m=rand()%10;
    cout<<n<<" "<<m<<el;
    for(int i=1;i<=m;i++){
        ll x=rand()%n,y=rand()%n,w=rand()%20;
        if(x==0) x=n;
        if(y==0) y=n;
        if(y==x) y=x-1;
        cout<<x<<" "<<y<<" "<<w<<el;
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    srand(time(0));
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}