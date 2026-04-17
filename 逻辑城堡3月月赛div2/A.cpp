#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s;
ll cnt[30];
void solve(){
    cin>>s;
    for(auto i:s) cnt[i-'a']++;
    for(auto i=0;i<26;i++){
        if(cnt[i]==1){
            cout<<char(i+'a');
            return;
        }
    }
    cout<<"Impossible";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("pair.in","r",stdin);
    freopen("pair.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}