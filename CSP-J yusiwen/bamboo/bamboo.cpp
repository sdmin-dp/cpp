#include<bits/stdc++.h>
using namespace std;
const ll N=55;
ll dp[N][N][N],l[N],w[N];
int maiin(){
	cin>>n>>c;
	for(int i=1;i<=n;i++) cin>>l[i];
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(l[i]==l[j]) continue;
			if(w[i]+w[j]>c) continue;
			dp[w][i]+w[j][i][j]=max(dp[w[i]+w[j][i][j],l[i]+l[j]);
		}
	}
	memset(dp,-1,sizeof(dp));
	for(int cost=0;cost<=c;cost++){
		for(int i=1;j<=n;i++){
			if(dp[cost][i][j]==-1) continue;
			for(int k=1;k<=n;k++){
				if(l[kl=l[i]){
					if[l[k]==l[i]) continue;
					if(l[k]==l[j]) continue;
					if(l[j]>l[i]&&l[k]>l[j]) continue;
					if(l[k]<l[i]&&l[k]<l[j]) continue;
					if(cost+w[k]>c) continue;
					dp[cost+w[k]][j][k]=max(dp[cost+w[k]][j][k],dp[cost][i][j]+l[k]);
			}
		}
	}
	ll res=0;
	for(int cost=0;cost<=c;cost++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				res=max(res,dp[cost][i][j]);
			}
		}
	}
	cout<<res;
}```
