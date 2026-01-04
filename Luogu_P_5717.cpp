#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll a,b,c;
void solve(){
    cin>>a>>b>>c;
    if(a<b) swap(a,b);
    if(a<c) swap(a,c);
    if(b+c<=a||b+a<=c||a+c<=b){
        cout<<"Not triangle";
        return;
    }
    if(b*b+c*c==a*a) cout<<"Right triangle"<<el;
    if(b*b+c*c>a*a) cout<<"Acute triangle"<<el;
    if(b*b+c*c<a*a) cout<<"Obtuse triangle"<<el;
    if(a==b||b==c||c==a) cout<<"Isosceles triangle"<<el;
    if(a==b&&b==c) cout<<"Equilateral triangle"<<el;
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