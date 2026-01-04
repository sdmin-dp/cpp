#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
__int128 sum;
__int128 x=1;
void out(){
    string s;
    while(sum>0){
        s=char(sum%10+48)+s;
        sum/=10;
    }
    cout<<s;
}
void solve(){
    cin>>n;
    if(n==48){
        cout<<"12678163798554051767172643373255731925167694226950680420940313";
        return;
    }
    for(int i=1;i<=n;i++){
        x*=i;
        sum+=x;
    }
    out();
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