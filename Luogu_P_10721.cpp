#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=20+5;
const ll M=1e6+5;
ll n,m;
ll a[N],dp[M];
string s;
ll sum;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=333333;j++)
            dp[j]=max(dp[j],dp[j-i]+a[i]);
    int i=0,k=0;
    s=s+"#  ";
	while(i<=m){
		if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c'){
			i+=3;
			k++;
		}
		else{
			i++;
			sum+=dp[k];
			k=0; 
		}
	}
	cout<<sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}