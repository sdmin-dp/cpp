#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
class bcj{
    public:
        vector<ll> fa,s;
        bcj(ll size){
            fa.resize(size+5);
            s.resize(size+5);
            for(int i=1;i<=size;i++){
                fa[i]=i;s[i]=1;
            }
        }
        ll find(ll x){
            if(x==fa[x]) return x;
            return fa[x]=find(fa[x]);
        }
};
struct node{
    ll first,second,third;
};
bool cmp(node x,node y){
    return x.third<y.third;
}
ll n,m;
node a[N];
void solve(){
    cin>>n>>m;
    bcj b(n);
    for(int i=1;i<=m;i++){
        cin>>a[i].first>>a[i].second>>a[i].third;
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        ll x=b.find(a[i].first),y=b.find(a[i].second);
        if(x!=y){
            b.fa[x]=y;
            b.s[y]+=b.s[x];
            if(b.s[y]>=n){
                cout<<a[i].third;
                return;
            }
        }
    }
    cout<<-1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}