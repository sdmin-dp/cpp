#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n,m;
ll tree[N];
ll a[N],ql[N],qr[N],qk[N];
ll vals[N*3];
ll v_size;
ll lowbit(ll x){
    return (x&-x);
}
void add(ll x,ll k){
    for(int i=x;i<=v_size;i+=lowbit(i)) tree[i]+=k;
}
ll getsum(ll x){
    ll res=0;
    for(int i=x;i>=1;i-=lowbit(i)) res+=tree[i];
    return res;
}
ll find_kth(ll k){
    ll idx=0;
    for(int i=20;i>=0;i--){
        ll nxt=idx+(1<<i);
        if(nxt<=v_size&&tree[nxt]<k){
            idx=nxt;
            k-=tree[nxt];
        }
    }
    return idx+1;
}
void solve(){
    cin>>n>>m;
    ll cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vals[cnt++]=a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>ql[i]>>qr[i]>>qk[i];
        vals[cnt++]=ql[i];
        vals[cnt++]=qr[i];
    }
    sort(vals,vals+cnt);
    v_size=0;
    for(int i=0;i<cnt;i++){
        if(i==0||vals[i]!=vals[v_size-1]){
            vals[v_size++]=vals[i];
        }
    }
    ll rem=n;
    for(int i=1;i<=n;i++){
        ll p=lower_bound(vals,vals+v_size,a[i])-vals+1;
        add(p,1);
    }
    for(int i=1;i<=m;i++){
        ll pos_l=lower_bound(vals,vals+v_size,ql[i])-vals+1;
        ll pos_r=lower_bound(vals,vals+v_size,qr[i]+1)-vals;
        if(pos_l>pos_r||getsum(pos_r)-getsum(pos_l-1)<qk[i]){
            cout<<-1<<" ";
            continue;
        }
        ll target=getsum(pos_l-1)+qk[i];
        ll idx=find_kth(target);
        cout<<vals[idx-1]<<" ";
        add(idx,-1);
        rem--;
    }
    cout<<el;
    cout<<rem;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}