#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x,res,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
map<ll,ll> mp;
ll change(ll a[]){
	ll res=0;
	for(int i=1;i<=9;++i) res=res*10+a[i];
	return res;
}
void bfs(){
	mp[123456780]=0;
	ll a[10]={0,1,2,3,4,5,6,7,8,0};
	queue<ll> q;q.push(123456780);
	while(q.size()){
		ll p=q.front(),x,y,xx,yy;q.pop();
		for(x=0;x<3;++x)
            for(y=1;y<=3;++y)
                if(p/int(pow(10,3*x+y))%10==0)
                    break;
		for(int i=0;i<4;++i){
			xx=x+dx[i],yy=y+dy[i];
			if(xx<0||xx>2||yy<0||yy>2) continue;
			swap(a[x*3+y],a[xx*3+yy]);
			ll z=change(a);
			if(mp[z]){
				swap(a[x*3+y],a[xx*3+yy]);
				continue;
			}
			mp[z]=mp[p]+1;
			q.push(z);
			swap(a[x*3+y],a[xx*3+yy]);
		}
	}
}//吴宇阳是gaynimm
int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    bfs();
    cin>>n;
    while(n--){
    	res=0;
    	for(int i=1;i<=9;++i) cin>>x,res=res*10+x;
    	cout<<mp[res]<<'\n';
	}
    return  0;
}
