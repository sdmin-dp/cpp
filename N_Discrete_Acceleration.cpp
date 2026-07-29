#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const double eps=1e-6;
ll n;
double h;
double a[N];
double get_l(double x){
    double len=0,time=0,v=1;
    for(int i=0;i<=n;i++){
        double t=a[i+1]-a[i];
        if(time+t/v<=x){
            len+=t;
            time+=t/v;
            v+=1;
        }else{
            double k=x-time;
            len+=k*v;
            break;
        }
    }
    return len;
}
double get_r(double x){
    double len=0,time=0,v=1;
    for(int i=n;i>=0;i--){
        double t=a[i+1]-a[i];
        if(time+t/v<=x){
            len+=t;
            time+=t/v;
            v+=1;
        }else{
            double k=x-time;
            len+=k*v;
            break;
        }
    }
    return len;
}
bool check(double x){
    return (get_l(x)+get_r(x))>=h;
}
void erfen(){
    double l=0,r=h,ans=0,mid=0;
    while(r-l>eps){
        mid=(l+r)/2;
        if(check(mid)){
            r=mid;
            ans=mid;
        }else{
            l=mid;
        }
    }
    printf("%.15lf\n",ans);
}
void solve(){
    cin>>n>>h;
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=h;
    erfen();
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