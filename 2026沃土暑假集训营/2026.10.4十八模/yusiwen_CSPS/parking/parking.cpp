#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e9+5;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
vector<ll> s={1,2,3,4,5,6,7,8,0};
map<ll,ll> ans;
ll hsh(vector<ll> s){
    ll res=0;
    for(auto i:s) res=res*10+i;
    return res;
}
vector<ll> rehsh(ll s){
    vector<ll> res;
    for(int i=1;i<=9;i++){
        res.push_back(s%10);
        s/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}
void init(){
    queue<ll> q;
    ll scode=hsh(s);
    q.push(scode);
    ans[scode]=0;
    while(!q.empty()){
        auto t=q.front();q.pop();ll x,y;
        // if(ans[t]!=0&&t!=123456780) continue;
        vector<ll> v=rehsh(t);
        ll c[4][4]={{0,0,0,0},{0,v[0],v[1],v[2]},{0,v[3],v[4],v[5]},{0,v[6],v[7],v[8]}};
        for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) if(c[i][j]==0) x=i,y=j;
        for(int i=0;i<4;i++){
            ll xx=x+dx[i],yy=y+dy[i];
            if(xx>0&&yy>0&&xx<=3&&yy<=3){
                swap(c[xx][yy],c[x][y]);
                vector<ll> res={c[1][1],c[1][2],c[1][3],c[2][1],c[2][2],c[2][3],c[3][1],c[3][2],c[3][3]};
                int ncode=hsh(res);
                if(!ans.count(ncode)){
                    q.push(ncode);
                    ans[ncode]=ans[t]+1;
                }
                swap(c[xx][yy],c[x][y]);
            }
        }
    }
}
void solve(){
    init();
    ll n;
    cin>>n;
    while(n--){
        vector<ll> v(9);
        cin>>v[0]>>v[1]>>v[2]>>v[3]>>v[4]>>v[5]>>v[6]>>v[7]>>v[8];
        cout<<ans[hsh(v)]<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}