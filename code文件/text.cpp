#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
class bcj{
    public:
        vector<ll> fa;
        bcj(ll size){
            fa.resize(size+5);
            for(int i=1;i<=size;i++){
                fa[i]=i;
            }
        }
        ll find(ll x){
            if(x==fa[x]) return x;
            return fa[x]=find(fa[x]);
        }
        void add(ll x,ll y){
            x=find(x),y=find(y);
            if(x!=y) fa[x]=y;
        }
};
void solve(){

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