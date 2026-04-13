#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s;
vector<ll> num1,num2,num3;
void solve(){
    cin>>s;
    ll len=s.size();
    num1.clear();
    num2.clear();
    num3.clear();
    for(ll i=0;i<len;i++){
        if(s[i]=='1') num1.push_back(i);
        else if(s[i]=='2') num2.push_back(i);
        else num3.push_back(i);
    }
    // cerr<<num1.size()<<" "<<num2.size()<<" "<<num3.size()<<el;
    if(num1.size()==0||num2.size()==0||num3.size()==0){
        cout<<0<<el;
        return;
    }
    ll ans=1e18;
    for(auto j:num2){
        ll i1=lower_bound(num1.begin(),num1.end(),j)-num1.begin();
        ll i2=(i1-1>=0?i1-1:1e18);
        ll k1=lower_bound(num3.begin(),num3.end(),j)-num3.begin();
        ll k2=(k1-1>=0?k1-1:1e18);
        ll I1=0,I2=0,K1=0,K2=0;
        /*i1 越界*/ if(i1<0||i1>=num1.size()) I1=1e18;
        /*i2 越界*/ if(i2<0||i2>=num1.size()) I2=1e18;
        /*k1 越界*/ if(k1<0||k1>=num1.size()) K1=1e18;
        /*k2 越界*/ if(k2<0||k2>=num1.size()) K2=1e18;
        if(I1!=1e18) I1=num1[i1];
        if(I2!=1e18) I2=num1[i2];
        if(K1!=1e18) K1=num3[k1];
        if(K2!=1e18) K2=num3[k2];
        // cerr<<j<<el;
        ll i=(abs(I1-j+1)>abs(I2-j+1)?I2:I1),k=(abs(K1-j+1)>abs(K2-j+1)?K2:K1);
        ll b=min({i,j,k}),e=max({i,j,k});
        // cerr<<i<<" "<<k<<el;
        ans=min(ans,e-b+1);
        // printf("i1:%lld,i2:%lld,k1:%lld,k2:%lld,j:%lld\n",i1,i2,k1,k2,j);
    }
    cout<<ans<<el;
    // cerr<<"num1:";for(int i:num1) cerr<<i<<" ";cerr<<el;
    // cerr<<"num2:";for(int i:num2) cerr<<i<<" ";cerr<<el;
    // cerr<<"num3:";for(int i:num3) cerr<<i<<" ";cerr<<el;
    // cout<<ans<<el;
    
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

/*
I1:1000000000000000000
i1:1
I2:0 yes
i2:0 
K1:2 yes
k1:0
K2:1000000000000000000
k2:1000000000000000000
*/