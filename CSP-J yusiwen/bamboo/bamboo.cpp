#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=55;
ll n,c;
ll dp[N][N][N],l[N],w[N];
int maiin(){
	cin>>n>>c;
	for(int i=1;i<=n;i++) cin>>l[i];
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(l[i]==l[j]) continue;
			if(w[i]+w[j]>c) continue;
			dp[w[i]]+w[j][i][j]=max(dp[w[i]]+w[j][i][j],l[i]+l[j]);
		}
	}
	ll res=0;
	memset(dp,-1,sizeof(dp));
	for(int cost=0;cost<=c;cost++){
		for(int i=1;i<=n;i++){
			if(dp[cost][i][j]==-1) continue;
			for(int k=1;k<=n;k++){
				if(l[k]=l[i]){
					if[l[k]==l[i]) continue;
					if(l[k]==l[j]) continue;
					if(l[j]>l[i]&&l[k]>l[j]) continue;
					if(l[k]<l[i]&&l[k]<l[j]) continue;
					if(cost+w[k]>c) continue;
                    if(dp[cost+w[k]][j][k]<dp[cost][i][j]+l[k]){
                        dp[cost+w[k]][j][k]+dp[cost][i][j]+l[k];
                        res=max(res,dp[cost][i][j]+l[k]);
                    }
			}
		}
	}
	for(int cost=0;cost<=c;cost++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				res=max(res,dp[cost][i][j]);
			}
		}
	}
	cout<<res;
}
