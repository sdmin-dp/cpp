#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
string s;
bool ishuiwen(string s){
    string t=s;
    reverse(t.begin(), t.end());
    return s==t;
}
void solve(){
    cin>>n>>m;
    cin>>s;
    ll cnt=0;
    sort(s.begin(), s.end());
    do{
        ll flag=0;
        for(int i=0;i<=n-m;i++){
            if(ishuiwen(s.substr(i, m))){
                flag=1;
                break;
            }
        }
        if(!flag) cnt++;
    }while(next_permutation(s.begin(), s.end()));
    cout<<cnt;
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