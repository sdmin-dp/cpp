#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,k;
ll a[N],b[N];

void solve(){
    cin>>n>>k;
    priority_queue<ll> q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        q.push(b[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=k;i++){
        if(a[i]<q.top()) a[i]=q.top();
        q.pop();
    }
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
    }
    cout<<sum<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}