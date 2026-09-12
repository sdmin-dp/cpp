#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,x;
ll t;
string s;
void solve(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        // cout<<c;
        if(c=='U'){
            if(x==1) continue;
            if(t>=1) t--;
            else x/=2;
        }
        else if(c=='L'){
            if(x*2>=1e12) t++;
            else x*=2;
        }
        else{
            if(x*2+1>1e12) t++;
            else x=x*2+1;
        }
        // cout<<x<<" ";
    }
    cout<<x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}