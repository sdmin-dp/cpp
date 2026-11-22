#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3000+5;
ll n,m;
pair<string,string> a[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        a[i].first=s;
        sort(s.begin(),s.end(),greater<char>());
        a[i].second=s;
    }
    for(int i=1;i<=n;i++){
        ll flag=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(a[i].first>=a[j].second){
                flag=0;
                break;
            }
        }
        cout<<flag;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}