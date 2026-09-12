#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e6+5;
ll m;
string t;
ll nxt[N];
void solve(){
    cin>>m>>t;
    for(int i=1,j=0;i<m;i++){
        while(j>0&&t[i]!=t[j]) j=nxt[j-1];
        if(t[i]==t[j]) j++;
        nxt[i]=j;
    }
    cout<<m-nxt[m-1];
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