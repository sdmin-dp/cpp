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
    for(ll i=0;i<len;i++){
        if(s[i]=='1') num1.push_back(i);
        else if(s[i]=='2') num2.push_back(i);
        else num3.push_back(i);
    }
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
        ll i=min(abs(num1[i1]-j),abs(num1[i2]-j)),k=min(abs(num3[k1]-j),abs(num3[k2]-j));
        ll I1=0,I2=0,K1=0,K2=0;
        /*i1 越界*/ if(i1<0||i1>=num1.size()) I1=1e18;
        /*i2 越界*/ if(i2<0||i2>=num1.size()) I2=1e18;
        /*k1 越界*/ if(k1<0||k1>=num1.size()) K1=1e18;
        /*k2 越界*/ if(k2<0||k2>=num1.size()) K2=1e18;

        // ll b=min({i,j,k}),e=max({i,j,k});
        // ans=min(ans,e-b+1);
        printf("i1:%lld,i2:%lld,k1:%lld,k2:%lld,j:%lld\n",i1,i2,k1,k2,j);
    }
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