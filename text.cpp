#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1005;
ll m,idx,dfn[N],low[N],dcc_cnt;
bool is_cut[N];
vector<ll> g[N],dcc[N];
stack<ll> stk;
set<ll> st;
void tarjan(ll x,ll root){
    dfn[x]=low[x]=++idx;
    stk.push(x);
    ll child=0;
    for(auto i:g[x]){
        if(!dfn[i]){
            child++;
            tarjan(i,root);
            low[x]=min(low[x],low[i]);
            if(low[i]>=dfn[x]){
                if(x!=root||child>1)is_cut[x]=1;
                dcc_cnt++;
                ll y;
                do{
                    y=stk.top();stk.pop();
                    dcc[dcc_cnt].push_back(y);
                }while(y!=i);
                dcc[dcc_cnt].push_back(x);
            }
        }else low[x]=min(low[x],dfn[i]);
    }
}
void solve(){
    ll T=0;
    while(cin>>m&&m){
        T++;
        for(int i=0;i<N;i++){
            g[i].clear();dcc[i].clear();
            dfn[i]=low[i]=is_cut[i]=0;
        }
        st.clear();while(!stk.empty())stk.pop();
        idx=dcc_cnt=0;
        for(int i=1;i<=m;i++){
            ll u,v;cin>>u>>v;
            g[u].push_back(v);g[v].push_back(u);
            st.insert(u);st.insert(v);
        }
        for(auto i:st)if(!dfn[i])tarjan(i,i);
        unsigned long long res_num=0,res_way=1;
        if(dcc_cnt==1){
            res_num=2;
            res_way=(unsigned long long)dcc[1].size()*(dcc[1].size()-1)/2;
        }else{
            for(int i=1;i<=dcc_cnt;i++){
                ll cnt=0;
                for(auto node:dcc[i])if(is_cut[node])cnt++;
                if(cnt==1){
                    res_num++;
                    res_way*=(dcc[i].size()-1);
                }
            }
        }
        cout<<"Case "<<T<<": "<<res_num<<" "<<res_way<<el;
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
