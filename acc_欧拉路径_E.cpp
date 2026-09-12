#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
int p[30],in[30],ot[30];
bool ex[30];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
void solve(){
    int n;cin>>n;
    for(int i=0;i<26;i++){p[i]=i;in[i]=ot[i]=ex[i]=0;}
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        int u=s[0]-'a',v=s[s.size()-1]-'a';
        ot[u]++;in[v]++;ex[u]=ex[v]=1;
        int fu=find(u),fv=find(v);
        if(fu!=fv)p[fu]=fv;
    }
    int c1=0,c2=0,rt=0;
    for(int i=0;i<26;i++){
        if(!ex[i])continue;
        if(p[i]==i)rt++;
        if(in[i]==ot[i])continue;
        if(ot[i]-in[i]==1)c1++;
        else if(in[i]-ot[i]==1)c2++;
        else{cout<<"The door cannot be opened."<<el;return;}
    }
    if(rt==1&&((c1==0&&c2==0)||(c1==1&&c2==1)))cout<<"Ordering is possible."<<el;
    else cout<<"The door cannot be opened."<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
