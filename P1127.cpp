#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll n;
vector<pair<ll,char>> g[130];
ll cnt1,cnt2,cnt3;
char start;
ll idx[130];
string s[N];
deque<ll> res;
ll in[130];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+n+1);
    for(int i=1;i<=n;i++){
        char u=s[i][0],v=s[i].back();
        g[u].push_back({i,v});
    }
    for(char i='a';i<='z';i++) sort(g[i].begin(),g[i].end());
    for(char i='a';i<='z';i++){
        if(in[i]+1==g[i].size()){
            cnt1++;
            start=i;
        }else if(in[i]==g[i].size()+1) cnt2++;
        else if(in[i]==g[i].size()) cnt3++;
    }
    if(!(cnt3==26||cnt1==1&&cnt2==1&&cnt1+cnt2+cnt3==26)){
        cout<<"***";
        return;
    }
    if(!start){
        for(char i='a';i<='z';i++){
            if(g[i].size()>=1){
                start=i;
                break;
            }
        }
    }
    dfs(start);
    
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