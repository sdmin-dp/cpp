#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e2+5;
ll n;
ll a[N][N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    ll ans=0;
    for(int x1=1;x1<=n;x1++){
        for(int y1=1;y1<=n;y1++){
            for(int x2=x1;x2<=n;x2++){
                for(int y2=y1;y2<=n;y2++){
                    ll mn=10000;
                    bool flag=1;
                    for(int i=x1;i<=x2;i++){
                        for(int j=y1;j<=y2;j++){
                            if(a[i][j]<mn) mn=a[i][j];
                            if(mn<100){
                                flag=0;
                                break;
                            }
                        }
                        if(!flag) break;
                    }
                    if(mn==100){
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
