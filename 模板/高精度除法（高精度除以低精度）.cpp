#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s;
ll t;
ll a[N];
ll p,q,m;
vector<ll> res;
void chu(){
     //先算整数部分
    for(int i=0;i<s.size();i++){
        p=p*10+s[i]-'0';
        res.push_back(p/t);
        p%=t;
    }
    q=res.size()-1;//保存个位的位置，用来输出小数点
    for(int i=0;i<=m;i++){//重复计算m+1位小数
        p=p*10;
        res.push_back(p/t);
        p%=t;
    }
    if(res[res.size()]>=5){ //处理进位
        res[res.size()-2]++;
        for(int i=res.size()-2;i>=0;i--){
            if(res[i]==10) res[i-1]++,res[i]=0;
            else break;
        }
    }
    res.pop_back();//丢掉第m+1位小数
    ll k=0;
    for(int i=0;i<res.size();i++){//找非前导零的最高位
        if(res[i]){
            k=i;
            break;
        }
    }
    for(int i=k;i<res.size();i++){//输出结果和小数点
        cout<<res[i];
        if(i==q&&res.size()!=q) cout<<'.';
    }
}
void solve(){
    cin>>s;
    cin>>t;
    cin>>m;
    //计算大整数s除以低精度整数t，保留m位小数​
    chu();
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