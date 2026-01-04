#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+5;
ll n;
struct node{
    ll ch,ma,en;
    ll zf;
}a[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].ch>>a[i].ma>>a[i].en;
        a[i].zf=a[i].ch+a[i].ma+a[i].en;
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(abs(a[i].ch-a[j].ch)<=5&&abs(a[i].ma-a[j].ma)<=5&&abs(a[i].en-a[j].en)<=5&&abs(a[i].zf-a[j].zf)<=10){
                cnt++;
            }
        
        }
    }
    cout<<cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}