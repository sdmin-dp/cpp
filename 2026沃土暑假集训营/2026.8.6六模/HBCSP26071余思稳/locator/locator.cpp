#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n,q;
ll a[N];
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=q;i++){
        string s;
        cin>>s;
        if(s=="balance"){
            ll l,r,x;
            cin>>l>>r>>x;
            for(int i=l;i<=r;i++) a[i]+=x;
        }else if(s=="recount"){
            ll l,r,x;
            cin>>l>>r>>x;
            for(int i=l;i<=r;i++) a[i]=x;
        }else if(s=="dispatch"){
            ll l,x;
            cin>>l>>x;
            ll sum=0;
            bool flag=0;
            for(int i=l;i<=n;i++){
                sum+=a[i];
                if(sum>=x){
                    cout<<i<<el;
                    flag=1;
                    break;
                }
            }
            if(!flag) cout<<-1<<el;
        }else if(s=="ledger"){
            ll l,r;
            cin>>l>>r;
            ll sum=0;
            for(int i=l;i<=r;i++){
                sum+=a[i];
            }
            cout<<sum<<el;
        }else if(s=="watch"){
            ll l,r,x;
            cin>>l>>r>>x;
            bool flag=0;
            for(int i=l;i<=r;i++){
                if(a[i]>=x){
                    flag=1;
                    cout<<i<<el;
                    break;
                }
            }
            if(!flag) cout<<-1<<el;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("locator.in","r",stdin);
    freopen("locator.out","w",stdout);
    ll T=1;
//    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
