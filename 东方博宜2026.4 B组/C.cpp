#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll A,B,C;
ll a,b,c;
ll hsh(pair<ll,ll> a){
    return a.first*10000+a.second;
}
pair<ll,ll> rehsh(ll a){
    return {a%10000,a/10000};
}
unordered_set<ll> st;
void solve(){
    cin>>A>>B>>C;
    a=0,b=0,c=C;
    ll ans=0,mn=1e12,cnt=0;
    while(st.find(hsh({a,b}))!=st.end()){
        cnt++;
        if(b==0){
            c+=a;
            a=0;
            c-=B;
            b=B;
        }else if(b!=0){
            if(A-a>=b){
                a+=b;
                b=0;
            }else{
                a=A;
                b-=A;
            }
        }
        if(a<mn&&a){mn=a;ans=cnt;}
        if(b<mn&&b){mn=b;ans=cnt;}
        if(c<mn&&c){mn=c;ans=cnt;}
        st.insert(hsh({a,b}));
    }
    cout<<mn<<"\n"<<ans;
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