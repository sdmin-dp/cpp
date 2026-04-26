#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll A,B,C,a,b,c;
ll to;
ll cnt1,cnt2;
// unordered_set<ll> st;
void solve(){
    cin>>A>>B>>C;
    a=b=0;c=C;
    to=__gcd(A,__gcd(B,C));
    while(a!=to&&b!=to&&c!=to){
        if(b==0){
            if(c<b) b=c,c=0;
            else if(c>=b) b=B,c-=B;
        }else if(a==A){
            c+=a;
            a=0;
        }else{
            if(A-a>=b) a+=b,b=0;
            else if(A-a<b) b-=(A-a),a=A;
        }
        cnt1++;
    }
    swap(A,B);
    a=0,b=0,c=C;
    while(a!=to&&b!=to&&c!=to){
        if(b==0){
            if(c<b) b=c,c=0;
            else if(c>=b) b=B,c-=B;
        }else if(a==A){
            c+=a;
            a=0;
        }else{
            if(A-a>=b) a+=b,b=0;
            else if(A-a<b) b-=(A-a),a=A;
        }
        cnt2++;
    }
    cout<<to<<el<<min(cnt1,cnt2);
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