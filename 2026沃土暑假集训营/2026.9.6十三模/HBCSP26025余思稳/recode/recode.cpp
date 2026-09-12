#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
pair<ll,pair<ll,ll>> a[N];
string s;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string t;
        cin>>t;
        a[i].second.first=s.size();
        s+=t;
        a[i].second.second=s.size()-1;
        a[i].first=pow(10,t.size()-1);
    }
    for(int i=1;i<=m;i++){
        char op;
        cin>>op;
        if(op=='C'){
            ll l,r,x,y;
            cin>>l>>r>>x>>y;
            l=a[l].second.first,r=a[r].second.second;
            for(int j=l;j<=r;j++) if(s[j]==char(x+48)) s[j]=char(y+48);
        }else if(op=='S'){
            ll l,r;
            cin>>l>>r;
            ll ans=0;
            for(int j=l;j<=r;j++){
                ll q=a[j].first;
                for(int k=a[j].second.first;k<=a[j].second.second;k++){
                    ans+=q*(s[k]-48);
                    q/=10;
                }
            }
            cout<<ans<<el;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("recode.in","r",stdin);
    freopen("recode.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}