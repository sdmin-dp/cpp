#include<bits/stdc++.h>
long long n,m,ans,a[100005];
int main(){
    std::cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){std::cin>>u>>v;a[u]++;a[v]++;}
	for (int i=1;i<=n;i++) ans+=a[i]*(a[i]-1)/2;
	std::cout<<ans;
}