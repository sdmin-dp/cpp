#include<iostream>
#define ll int
using namespace std;
#define el '\n'
const ll N=5e2+5;
ll n;
ll a[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    long long ans=0;
    for(int x1=1;x1<=n;x1++){
        for(int y1=1;y1<=n;y1++){
            for(int x2=1;x2<=n;x2++){
                for(int y2=1;y2<=n;y2++){
                    ll mn=10000;
                    for(int i=x1;i<=x2;i++){
                        for(int j=y1;j<=y2;j++){
                            mn=min(mn,a[i][j]);
                        }
                    }
                    if(mn==100){
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}