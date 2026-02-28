#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll sum;
string s;
map<char,ll> mp;
map<ll,char> mp2;

ll a[]={1000,100,10,1};
void solve(){
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;
    mp2[1]='I';
    mp2[5]='V';
    mp2[10]='X';
    mp2[50]='L';
    mp2[100]='C';
    mp2[500]='D';
    mp2[1000]='M';
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        ll last=1e9,num=0;
        for(char i:s){
            num+=mp[i];
            if(last<mp[i]) num-=2*last;
            last=mp[i];
        }
        if(sum+num>3999){cout<<"ERROR";return;}
        else sum+=num;
    }
    string ans;
    for(auto i:a){
        ll k=sum/i;
        sum%=i;
        cerr<<k<<" ";
        if(k==9){
            ans+=mp2[i];
            ans+=mp2[i*10];
            continue;
        }
        else if(k==4){
            ans+=mp2[i];
            ans+=mp2[i*5];
            continue;
        }
        else if(k>=5){
            k-=5;
            ans+=mp2[i*5];
        }
        for(int j=1;j<=k;j++) ans+=mp2[i];
    }
    cout<<ans;
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