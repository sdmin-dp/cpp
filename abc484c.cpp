#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
ll a[N],b[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    ll L=1;
    while(L<=n&&a[L]==b[L]) L++;
    if(L>n){cout<<"Yes"<<el;return;}
    ll R=n;
    while(R>=1&&a[R]==b[R]) R--;
    bool ok=false;
    if(a[L]==b[R]){
        bool flag=true;
        for(int i=L;i<R;i++){
            if(a[i+1]!=b[i]){flag=false;break;}
        }
        if(flag) ok=true;
    }
    if(!ok&&a[R]==b[L]){
        bool flag=true;
        for(int i=L;i<R;i++){
            if(a[i]!=b[i+1]){flag=false;break;}
        }
        if(flag) ok=true;
    }
    cout<<(ok?"Yes":"No")<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}