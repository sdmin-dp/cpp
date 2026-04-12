#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll a,b,t;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}
void solve(){
    cin>>a>>b>>t;
    //特判
    if(t%__gcd(a,b)!=0){
        cout<<-1;
        return;
    }

    //step 1.算出方程的一组解
    ll x,y,gcd;
    gcd=exgcd(a,b,x,y);
    x=t/gcd*x,y=t/gcd*y;

    //step 2 算出k和q
    //y-k,x+q
    //b*k=a*q,b/a*k=q,k|a/gcd(a,b)->\
    k=a/gcd(a,b),q=b/gcd(a,b)
    ll k=a/gcd,q=b/gcd;

    //y-mk>0\
      x+mq>0
    /*
        y>mk,mk<y,m<y/k,m_max=y/k (如果y/k是整数，m_max=y/k-1;否则，m_max=y/k向下取整)
        mq>-x,m>-x/q,m_min=-x/q (m_min=-x/q+1)
    */
    ll m_max=(y%k==0?y/k-1:(ll)y/k),m_min=(ll)(-x/q)+1;
    ll sum=m_max-m_min+1;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}