#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll a,b,c;
void solve(){
    c=rand()%5000;if(c==0) c=5000;
    b=rand()%5000;if(b==0) b=5000;
    a=rand()%5000;if(a==0) a=5000;
    cout<<a<<" "<<b<<" "<<c;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    srand(time(0));
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}