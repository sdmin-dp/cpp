#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll A,B,C,a,b,c;
ll to;
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
        }els
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