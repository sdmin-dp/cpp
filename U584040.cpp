#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
bool flag=0;
deque<ll> dq;
void solve(){
    cin>>n;
    if(n<0){
        flag=1;
        n=abs(n);
    }
    while(n){
        ll k=n%3;
        n/=3;
        dq.push_back(k);
    }
    reverse(dq.begin(),dq.end());
    
    if(dq[0]==2){
        dq.push_front(1);
        dq[1]=-1;
     }for(int i=0;i<dq.size();i++) cerr<<dq[i];
    for(int i=dq.size()-1;i>=0;i--){
        if(dq[i]==2){
            dq[i-1]++;
            dq[i]=-1;
            // cerr<<"dog";
        }else if(dq[i]==3){
            dq[i-1]++;
            dq[i]=0;
            
        }
    }
    if(flag==1){
        for(int i=0;i<dq.size();i++){
            if(dq[i]==1) dq[i]=-1;
            else if(dq[i]==-1) dq[i]=1;
        }
    }
    for(int i=0;i<dq.size();i++){
        if(dq[i]==-1) cout<<'Z';
        else cout<<dq[i];
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