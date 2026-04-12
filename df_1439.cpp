#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
bool isprime[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0};
ll ans[N];
ll vis[N];
ll sum=0;
void dfs(ll x){
    if(sum>=10) exit(0);
    if(x==n+1){
        if(sum<10&&isprime[ans[n]+ans[1]]&&ans[1]==1){
            for(int i=1;i<=n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<el;
            sum++;
        }
        
        return;
    }
    if(x==1){
        vis[1]=1;
        ans[x]=1;
        dfs(x+1);
        return;
    }
    for(ll i=1;i<=n;i++){
        if(isprime[ans[x-1]+i]&&!vis[i]){
            vis[i]=1;
            ans[x]=i;
            dfs(x+1);
            ans[x]=0;
            vis[i]=0;
        }
    }
}
void solve(){
    cin>>n;
    if(n%2==1){
        return;
    }
    dfs(1);
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
/*
1 2 3 4 7 6 5 8 9 10 13 16 15 14 17 12 11 18 
1 2 3 4 7 6 5 8 9 10 13 18 11 12 17 14 15 16 
1 2 3 4 7 6 5 8 15 16 13 10 9 14 17 12 11 18 
1 2 3 4 7 6 5 8 15 16 13 18 11 12 17 14 9 10 
1 2 3 4 7 6 5 12 17 14 9 10 13 16 15 8 11 18 
1 2 3 4 7 6 5 12 17 14 9 10 13 18 11 8 15 16 
1 2 3 4 7 6 5 12 17 14 15 16 13 10 9 8 11 18 
1 2 3 4 7 6 5 12 17 14 15 16 13 18 11 8 9 10 
1 2 3 4 7 6 5 14 17 12 11 18 13 10 9 8 15 16 
1 2 3 4 7 6 5 14 17 12 11 18 13 16 15 8 9 10 

*/