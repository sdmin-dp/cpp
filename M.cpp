#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el endl
const ll N=1e5+5;
struct node{ll a,b,c;};
bool cmpa(node a,node b){return a.a<b.a;}
bool cmpb(node a,node b){return a.b<b.b;}
bool cmpc(node a,node b){return a.c<b.c;}
void solve(){
    ll n;
    cin>>n;
    vector<node> a;
    a.reserve(n+1);
    a.resize(n+1);
    for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c;
    sort(a.begin()+1,a.end(),cmpa);
    ll l=1,r=n,mid=0,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        ll qa,qb,qc;
        qa=a[mid].a;
        sort(a.begin()+1,a.begin()+mid,cmpb);
        sort(a.begin()+mid+1,a.end(),cmpc);
        qb=(l+mid)/2;
        qc=(mid+1+r)/2;
        ll ol=l,olr=r;
        cout<<"? "<<qa<<" "<<qb<<" "<<qc<<el;
        char f1,f2,f3;cin>>f1>>f2>>f3;
        if(f1=='1') r=mid-1;
        else l=mid+1,ans=mid;
        if(f2=='1') r=min(r,(ol+mid)/2-1);
        else l=max(l,(ol+mid)+1),ans=(ol+mid);
        if(f3=='1') r=min(r,(mid+1+olr)/2-1);
        else l=max(l,(mid+1+olr)/2+1),ans=(mid+1+olr)/2;
        sort(a.begin()+1,a.end(),cmpa);
    }
    cout<<"! "<<a[ans].a<<" "<<a[ans].b<<" "<<a[ans].c<<endl;
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}