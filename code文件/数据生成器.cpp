#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll mod=15;
ll n;
vector<ll> a,b;
void solve(){
    n=rand()%mod;if(n==0) n=mod;
    cout<<n<<el;
    ll k=rand()%mod,cnt=0;
    for(int i=1;i<=n;i++){
        a.push_back(i);
        b.push_back(i);
    }
    do{
        cnt++;
        if(cnt>=k) break;
    }while(next_permutation(a.begin(),a.end()));
    for(auto i:a) cout<<i<<" ";
    cout<<el;
    k=rand()%mod,cnt=0;
    do{
        cnt++;
        if(cnt>=k) break;
    }while(next_permutation(b.begin(),b.end()));
    for(auto i:b) cout<<i<<" ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    srand(time(0));
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}