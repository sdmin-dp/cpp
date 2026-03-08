#include<bits/stdc++.h>
long long n,a,b,x,y;
int main(){
    std::cin>>n>>a>>b;
    while(n--){
        std::cin>>x>>y;
        if(x==y) std::cout<<0<<'\n';
        else if(x==1||y==1) std::cout<<a<<'\n';
        else if(std::__gcd(x,y)==1) std::cout<<std::min(a,2*b)<<'\n';
        else std::cout<<std::min(2*a,b)<<'\n';
    }
}