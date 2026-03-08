#include<bits/stdc++.h>
long long n,a,b,x,y;
int main(){
    cin>>n>>a>>b;
    while(n--){
        cin>>x>>y;
        if(x==y) cout<<0<<el;
        else if(x==1||y==1) cout<<a<<el;
        else if(__gcd(x,y)==1) cout<<min(a,2*b)<<el;
        else cout<<min(2*a,b)<<el;
    }
    return 0;
}