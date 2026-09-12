#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=205+5;
int n,m,ans,g[N][26],cnt[N],idx;
string s;
bool dp[1024*1024+5];
void insert(){
    ll p=0;
    for(int i=s.size()-1;i>=0;i--){
        auto x=s[i]-'a';
        if(!g[p][x]) g[p][x]=++idx;
        p=g[p][x];
    }
    cnt[p]++;
}
void solve(){
    cin>>n>>m;
    while(n--){
        cin>>s;
        insert();
    }
    while(m--){
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        ans=0;
        cin>>s;
        s=' '+s;
        for(int i=1;i<s.size()&&i<=ans+10;i++){
            ll j=i,p=0;
            while(j>0&&i-j+1<=10){
                auto x=s[j]-'a';
                if(!g[p][x]) break;
                p=g[p][x];
                if(cnt[p]&&dp[j-1]){dp[i]=1;ans=i;}
                j--;
            }
        }
        cout<<ans<<el;
    }
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}