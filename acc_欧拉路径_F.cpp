#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e3+5;
ll cnt=0;
ll a[N][N];
map<pair<ll,ll>,ll> id;
ll n;
deque<ll> ans;
void dfs(ll x){
    for(int i=1;i<=n;i++){
        if(a[x][i]){
            a[x][i]--;
            a[i][x]--;
            dfs(i);
        }
    }
    ans.push_front(x);
}
void solve(){
    while(1){
        ll x,y,w;
        cin>>x>>y;
        if(cnt==1&&x!=0&&y!=0){
            //初始化
            n=0;
            id.clear();
            memset(a,0,sizeof(a));
            ans.clear();
        }
        if(x==0&&y==0){
            cnt++;
            if(cnt==2) break;
            //开始计算
            ll b=1;
            cerr<<cnt<<" ";
            ll cnt=0;
            ll cntou=0;
            for(int i=1;i<=n;i++){
                cnt=0;
                for(int j=1;j<=n;j++) cnt+=a[i][j];
                if(cnt%2){
                    b=i;
                    cntou++;
                }
            }
            if(!(cntou==0||cntou==2)){
                cout<<"Round trip does not exist.\n";
                continue;
            }
            dfs(b);
            for(int i=1;i<ans.size();i++) cout<<id[{i,ans[i]}]<<" ";
            cout<<el;
        }
        else{
            n++;
            cin>>w;
            a[x][y]++;
            a[y][x]++;
            id[{x,y}]=w;
            id[{y,x}]=w;
        }
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