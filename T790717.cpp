#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll l,r;
void solve(){
    cin>>l>>r;
    ll cnt=0;
    for(int a=l;a<=r;a++){
        for(int b=l;b<=r;b++){
            for(int c=l;c<=r;c++){
                for(int d=l;d<=r;d++){
                    if(a*d-c*b==0){
                        cnt++;
                    }
                }
            }
        }
    }
    cout<<cnt;
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