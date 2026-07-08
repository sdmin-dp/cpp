#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n;
string s;
ll ans[N];
void solve(){
    cin>>n;
    cin>>s;
    ll L=1,R=n;
    bool reversed=0;
    for(int i=n;i>=1;i--){
        if(s[i-1]=='o'){
            if(!reversed) {
                ans[L]=i;
                L++;
            }else{
                ans[R]=i;
                R--;
            }
            reversed=!reversed;
        }else{
            if(!reversed){
                ans[R]=i;
                R--;
            }else{
                ans[L]=i;
                L++;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}