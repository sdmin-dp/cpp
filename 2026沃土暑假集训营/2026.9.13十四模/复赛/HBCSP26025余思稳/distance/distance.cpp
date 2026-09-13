#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,k;
ll a[N];
ll sum[N];
priority_queue<ll> q;
bool check(){
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            return 0;
        }
    }
    return 1;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    if(k==1){
        sort(a+1,a+n+1);
        cout<<a[1];
    }else if(check()){
        ll b=n,i=1;
        while(k>b){
            b+=n;b-=i++;
        }
        cout<<a[1]*i;
    }else{
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                q.push(sum[r]-sum[l-1]);
                if(q.size()>k){
                    q.pop();
                }
            }
        }
        cout<<q.top();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("distance.in","r",stdin);
    freopen("distance.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}