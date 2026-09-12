#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
void solve(){
    cin>>n;
    if(n==1){
        cout<<"AB+C*DEF+/-";
        cout<<el;
    }if(n==2){
        cout<<9;
        cout<<el;
    }if(n==3){
        cout<<"DEBFGCA";
        cout<<el;
    }if(n==4){
        cout<<37;
        cout<<el;
    }if(n==5){
        cout<<"f";
        cout<<el;
    }if(n==6){
        cout<<4;
        cout<<el;
    }if(n==7){
        cout<<26;
        cout<<el;
    }if(n==8){
        cout<<"4 5 6";
        cout<<el;
    }if(n==9){
        cout<<"O(n log n)";
        cout<<el;
    }if(n==10){
        cout<<50;
        cout<<el;
    }
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