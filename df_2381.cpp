#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e6+5;
int g[N][30]/*邻接矩阵*/,idx/*记录编号*/;
ll cnt[N];
ll n,m;
void insert(string s){
    ll p=0;//从根节点开始找
    //循环每个字符
    for(int i=0;i<s.size();i++){
        ll x=s[i]-'a';
        //如果p和x之间没有边
        if(!g[p][x]) g[p][x]=++idx;
        p=g[p][x];
    }
    cnt[p]++;//以当前字符串的最后一个字符结尾的单词数加一
}
int find(string s){
    ll p=0;//从根节点开始找
    //循环每个字符
    for(int i=0;i<s.size();i++){
        ll x=s[i]-'a';
        //如果p和x之间没有边
        if(!g[p][x]) return 0;
        p=g[p][x];
    }
    return cnt[p];
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        insert(s);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        string s;
        cin>>s;
        cout<<find(s)<<el;
    }
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