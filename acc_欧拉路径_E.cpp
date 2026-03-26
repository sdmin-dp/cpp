#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=30;
ll n,in,ot;
bool ex;
int p;
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
void solve(){
    cin>>n;
    for(int i=0;i<26;i++){
        p[i]=i;
        in[i]=ot[i]=ex[i]=0;
    }
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int u=s[0]-'a',v=s[s.size()-1]-'a';
        ot[u]++;in[v]++;
        ex[u]=ex[v]=1;
        int fu=find(u),fv=find(v);
        if(fu!=fv) p[fu]=fv;
    }
    int cnt=0;
    for(int i=0;i<26;i++) if(ex[i]&&p[i]==i) cnt++;
    if(cnt>1){
        cout<<"The door cannot be opened."<<el;
        return;
    }
    int s1=0,s2=0;
    bool ok=1;
    for(int i=0;i<26;i++){
        if(!ex[i]) continue;
        if(in[i]==ot[i]) continue;
        if(ot[i]-in[i]==1) s1++;
        else if(in[i]-ot[i]==1) s2++;
        else ok=0;
    }
    if(ok&&((s1==0&&s2==0)||(s1==1&&s2==1))) cout<<"Ordering is possible."<<el;
    else cout<<"The door cannot be opened."<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--) solve();
    return 0;
}
