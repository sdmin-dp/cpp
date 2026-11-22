#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=3e5+5;

ll n,a[N],ans[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) ans[i]=1e18;
    ll c1=-1,p1=-1,c2=-1,p2=-1;
    for(int i=1;i<=n;i++){
        if(c1!=-1&&a[i]!=c1) ans[i]=min(ans[i],i-p1);
        else if(c2!=-1&&a[i]!=c2) ans[i]=min(ans[i],i-p2);
        if(a[i]==c1){
            p1=i;
        }else{
            c2=c1;p2=p1;
            c1=a[i];p1=i;
        }
    }
    c1=-1;p1=-1;c2=-1;p2=-1;
    for(int i=n;i>=1;i--){
        if(c1!=-1&&a[i]!=c1) ans[i]=min(ans[i],p1-i);
        else if(c2!=-1&&a[i]!=c2) ans[i]=min(ans[i],p2-i);
        if(a[i]==c1){
            p1=i;
        }else{
            c2=c1;p2=p1;
            c1=a[i];p1=i;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<el;
}
int main() {
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