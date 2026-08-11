#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
bool has_shuki(string s){
    for(int i=0;i+4<s.size();i++){
        string t=s.substr(i,5);
        if(t=="shuki") return 1;
    }
    return 0;
}
bool has_daishuki(string s){
    for(int i=0;i+7<s.size();i++){
        string t=s.substr(i,8);
        if(t=="daishuki") return 1;
    }
    return 0;
}
bool has_kirai(string s){
    for(int i=0;i+4<s.size();i++){
        string t=s.substr(i,5);
        if(t=="kirai") return 1;
    }
    return 0;
}
void solve(){
    cin>>n>>m;
    ll m1=m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(has_kirai(s)) m=min(m,0ll);
        else if(has_daishuki(s)) m+=2;
        else if(has_shuki(s)) m++;
        else m--;
    }
    ll m2=m;
    if(m2>0) cout<<m2-m1;
    else cout<<"shuki";
}
int main(){
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