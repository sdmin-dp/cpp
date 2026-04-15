#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll A,B,C;
unordered_set<pair<ll,ll>> st;
ll a,b,c;
void solve(){
    cin>>A>>B>>C;
    a=0,b=0,c=C;
    while(st.find({a,b})!=st.end()){
        if(b==0){
            c+=a;
            a=0;
            c-=B;
            b=B;
        }else if(b!=0){
            if(a>=b){
                a+=b;
                b=0;
            }else{
                a=A;
                b-=A;
            }
        }
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