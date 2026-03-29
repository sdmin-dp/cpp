#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
void solve(){
    n=rand()%15;if(n==0) n=15;
    m=rand()%15;if(m==0) m=15;
    cout<<n<<" "<<m<<el;
    for(int i=1;i<=m;i++){
        ll x,y;
        x=rand()%n;if(x==0) x=n;
        y=rand()%n;if(y==0) y=n;
        cout<<x<<" "<<y<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    srand(time(NULL));
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}