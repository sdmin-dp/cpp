#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
char no(){
    cout<<0;
    exit(0);
}
ll n;
ll in[N];
string s,last,t;
vector<ll> g[N];
ll dep[N];
ll ctoll(char c){
    return (c-'a'+1);
}
void sort(){
    queue<ll> q;
    for(int i=1;i<=26;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        if(q.size()>=2) no();
        ll x=q.front();
        q.pop();
        for(auto i:g[x]){
            if(!--in[i]){
                q.push(i);
                dep[i]=dep[x]+1;
            }
        }       
    }
}
void solve(){
    cin>>n;
    cin>>last;
    for(int i=1;i<=26;i++) in[i]=-1;
    for(int i=2;i<=n;i++){
        cin>>s;
        // if(s<last) no();
        for(ll i=0;i<last.size();i++){
            if(s[i]>last[i]){
                g[ctoll(last[i])].push_back(ctoll(s[i]));
                if(in[ctoll(last[i])]==-1) in[ctoll(last[i])]=0;
                if(in[ctoll(s[i])]==-1) in[ctoll(s[i])]=0;
                in[ctoll(s[i])]++;
                break;
            }
        }
        last=s;
    }
    for(int i=1;i<=26;i++){
        cerr<<char(i-1+'a')<<":";
        for(auto j:g[i]){
            cerr<<char(j-1+'a')<<" ";
        }
        cerr<<el;
    }
    cin>>t;
    for(auto i:t) if(in[ctoll(i)]==-1) no();
    for(auto i:t){
        cout<<char(dep[ctoll(t[i])]-'a'+1);
    }
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