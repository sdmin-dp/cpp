#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=400+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
string s;
ll pos[3][N];
ll cnt[3];
ll dp[N][N][3];
char lltoc(ll x){return char(x+48);}
ll ctoll(char c){return c-48;}
void solve(){
	cin>>s;
	s=' '+s;
	ll n=s.size()-1;
	for(int i=1;i<=n;i++)
		pos[ctoll(s[i])][++cnt[ctoll(s[i])]]=i;
	for(int i=0;i<3;i++){
		if(cnt[i]>(n+1)/2){
			cout<<-1;
			return;
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	dp[0][0][1]=0;
	dp[0][0][2]=0;
	for(ll i=1;i<=n;i++){
		for(ll a=0;a<=min(i,cnt[0]);a++){
			for(ll b=min(i-a,cnt[1]);b>=0;b--){
				ll c=i-a-b;
				ll x0=inf,x1=inf,x2=inf;
				if(a>0) x0=min(dp[a-1][b][1],dp[a-1][b][2])+abs(pos[0][a]-i);
				if(b>0) x1=min(dp[a][b-1][0],dp[a][b-1][2])+abs(pos[1][b]-i);
				if(c>0) x2=min(dp[a][b][0],dp[a][b][1])+abs(pos[2][c]-i);
				dp[a][b][0]=x0;
                dp[a][b][1]=x1;
                dp[a][b][2]=x2;
			}
		}
	}
	ll ans=min({dp[cnt[0]][cnt[1]][0],dp[cnt[0]][cnt[1]][1],dp[cnt[0]][cnt[1]][2]});
	cout<<ans/2;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ll T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}