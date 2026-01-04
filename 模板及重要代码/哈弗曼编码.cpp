#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s;
map<char,ll> mp;
struct node{
    char ch;
    ll cnt;
    node *left=nullptr,*right=nullptr;
    
};
//树
struct pnode{
    ll cnt;
    char c;
    node *home;
    bool operator <(const pnode b)const{
        if(cnt==b.cnt) return c>b.c;
        return cnt>b.cnt;
    }
};
priority_queue<pnode> q;
node a[N+N];
vector<ll> dq;
void print(){
    for(bool i:dq) cout<<i;
    cout<<el;
}
void dfs(node *r,ll k){
    if(r->ch!='*') cout<<r->ch<<" "<<k<<" ",print();
    if(r->left){
        dq.push_back(0);
        dfs(r->left,k+1);
        dq.pop_back();
    }
    if(r->right){
        dq.push_back(1);
        dfs(r->right,k+1);
        dq.pop_back();
    }
}
ll n;
void solve(){
    cin>>s;
    for(int i=0;i<s.size();i++) mp[s[i]]++;
    for(auto i:mp){
        node p;
        p.ch=i.first;
        p.cnt=i.second;
        a[n]=p;
        q.push({p.cnt,p.ch,&a[n]});
        n++;  
    }
    while(q.size()>1){
        pnode pp=q.top();q.pop();
        pnode qq=q.top();q.pop();
        a[n].ch='*';
        a[n].cnt=pp.cnt+qq.cnt;
        a[n].left=pp.home;
        a[n].right=qq.home;
        q.push({a[n].cnt,a[n].ch,&a[n]});
        n++;
    }
    node *root=q.top().home;
    dfs(root,0);
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