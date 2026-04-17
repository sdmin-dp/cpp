#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
double l;
double x[N];
void solve(){
    cin>>n>>l;
    for(int i=2;i<=n;i++){
        cin>>x[i];
    }
    for(int i=2;i<=n;i++){
        if(abs(x[i]-x[i-1])>=l){
            cout<<-1;
            return;
        }
    }
    double c=x[n];
    ll ans=n;
    for(int i=n-1;i>=1;i--){
        double li=x[i]-l/2.0,ri=x[i]+l/2.0;
        double lI=x[i+1]-l/2.0,rI=x[i+1]+l/2.0;
        ll C=c/((n-i+1)*1.0);
        if(C>=li&&C<=ri&&C>=lI&&C<=rI){
            ans--;
        }
        c+=x[i];
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
    srand(time(0));
    while(T--){
        solve();
    }
    return 0;
}