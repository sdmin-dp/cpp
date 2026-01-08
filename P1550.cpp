#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e2+5;
ll n;
ll a[N];
struct node{
    ll first,second,third;
};
class bcj{
    public:
        vector<ll> fa;
        bcj(ll size){
            fa.resize(size+5);
            for(int i=0;i<=size;i++) fa[i]=i;
        }
        ll find(ll x){
            if(x==fa[x]) return x;
            return fa[x]=find(fa[x]);
        }
};
bool cmp(node x,node y){
    return x.third<y.third;
}
ll g[N][N];
vector<node> v;
void solve(){
    cin>>n;
    bcj b(n);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
            if(i!=j){
                node x={i,j,g[i][j]};
                v.push_back(x);
            }
        }
    }
    for(int i=1;i<=n;i++) v.push_back({0,i,a[i]});
    sort(v.begin(),v.end(),cmp);
    ll sum=0;
    ll cnt=0;
    for(auto i:v){
        if(b.find(i.first)!=b.find(i.second)){
            sum+=i.third;
            b.fa[b.find(i.first)]=b.fa[b.find(i.second)];
            cnt++;
        }
        if(cnt==n) break;
    }
    cout<<sum;
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