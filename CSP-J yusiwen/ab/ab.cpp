#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=10+5;
string s;
ll n;
ll a[N];
ll cnt;
void solve(){
    cin>>s;
    n=s.size();
    for(int i=0;i<s.size();i++) a[i+1]=s[i]-'A'+1;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                cnt++;
            }
        }
    }
    cout<<cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ab.in","r",stdin);
    freopen("ab.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}