#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
struct node{
    string s,Pre,pre,Suf,suf,Num,num;
    void init(){
        int i=0;
        for(;i<s.size();i++){
            if('0'<=s[i]&&s[i]<='9') break;
            Pre.push_back(s[i]);
            // cerr<<Pre[i]<<" ";
            // cerr<<"dog";
        }
        // cout<<Pre[i]<<el;
        for(;i<s.size();i++){
            if(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z')) break;
            Num.push_back(s[i]);
            // cerr<<Num[i]<<" ";
        }
        for(;i<s.size();i++){
            Suf.push_back(s[i]);
            // cerr<<"dog";
        }
        for(int i=0;i<Pre.size();i++){
            char c=Pre[i];
            if('A'<=c&&c<='Z') pre.push_back(c-'A'+'a');
            else pre.push_back(c);
            // cerr<<"dog";
        }
        for(int i=0;i<Suf.size();i++){
            char c=Suf[i];
            if('A'<=c&&c<='Z') suf.push_back(c-'A'+'a');
            else suf.push_back(c);
            // cerr<<"dog";
        }
        num=Num;
        int j=0;
        for(;j<num.size()-1;j++){
            if(num[j]!='0') break;
            // cerr<<"dog";
        }
        // cerr<<j<<" ";
        num.erase(0,j);
        // cerr<<num<<el;
    }

};
bool cmpnum(string x,string y){
    if(x.size()>y.size()) return 0;
    else if(x.size()<y.size()) return 1;
    else return x<y;
}
bool cmp(node x,node y){
    if(x.pre!=y.pre) return x.pre<y.pre;
    else if(x.num!=y.num) return cmpnum(x.num,y.num);
    else return x.suf<y.suf;
}
ll n;
node a[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s;
        a[i].init();
    }
    // for(int i=1;i<=n;i++){
    //     cerr<<a[i].s<<" "<<a[i].Pre<<" "<<a[i].pre<<" "<<a[i].Num<<" "<<a[i].num<<" "<<a[i].Suf<<" "<<a[i].suf<<el;
    // }
    stable_sort(a+1,a+n+1,cmp);    
    for(int i=1;i<=n;i++){
        cout<<a[i].s<<el;
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