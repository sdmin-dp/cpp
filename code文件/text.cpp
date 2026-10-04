//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
//张博涵是gay
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define W(i) while(i)
#define el '\n'
const ll N=5000+5,M=1<<20;//12 or 16 or 20 or 24都可以
char buf[M],*p1=buf,*p2=buf,out[M],*p3=out;
//#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,M,stdin)),*p1++)//更快，但是好像有的数据会出现未定义EOF行为，有WA可能，但读1e8个数据比下面快700ms(洛谷实测)
#define gc() (p1==p2?(p2=(p1=buf)+fread(buf,1,M,stdin),p1==p2?EOF:*p1++):*p1++)
#define flush() (fwrite(out,1,p3-out,stdout),p3=out)
#define pc(c) (p3==(out+M)?(flush(),*p3++=(c)):*p3++=(c))
inline ll read(){//保险用long long,卡常用int
    ll x=0,f=1;
    char ch=gc();
    W(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=gc();
    }
    W(isdigit(ch)){
        x=x*10+(ch-'0');
        ch=gc();
    }
    return x*f;
}
inline void write(ll x){
    if(x<0){
        pc('-');
        x=-x;
    }
    if(x==0){
        pc('0');
        return;
    }
    char s[50];
    int len=0;
    W(x){
        s[len++]=char('0'+x%10);
        x/=10;
    }
    W(len) pc(s[--len]);
    return;
}
ll n,k;//如果n,k,a[i]>int快读用long long,int快读在洛谷上比long long快20-30ms(tips:ctrl c+ctrl v复制一个，改成readint(),readll()也行)
ll a[N];
ll dp[N][N];
ll mx=-1e9,mn=1e9;
bool check(ll x){
    // len-1
    vector<int> pre1(n+1,1);
    // len-2
    vector<int> pre2(n+1,0);
    // len
    vector<int> now(n+1,0);
    for(register ll len=2;len<=n;len++){//TLE就不#define ll long long,都手写long long(老王告诉我的)
        for(register ll l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            ll c1=pre1[l]+1;
            ll c2=pre1[l+1]+1;
            ll c3=1e18;
            if(llabs(a[r]-a[l])<=x){
                c3=pre2[l+1];
            }
            //now[l]=min({c1,c2,c3});
            ll tmp=(c2<c3?c2:c3);
            now[l]=(c1<tmp?c1:tmp);
        }
        pre2.swap(pre1);
        pre1.swap(now);
    }
    return pre1[1]<=k;
}   
void erfen(){
    ll l=0,r=mx-mn+5,mid=0,ans=0;
    for(register int i=1;i<=n;i++) dp[i][i]=1;
    while(l<=r){
        mid=(l+r)>>1;//改位运算快！
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    write(ans);
}
void solve(){
    n=read();
    k=read();
    for(register int i=1;i<=n;i++){
        a[i]=read();
        //mx=max(mx,a[i]);//用自带max,min函数慢
        mx=(mx<a[i]?a[i]:mx);
        //mn=min(mn,a[i]);//同理
        mn=(mn>a[i]?a[i]:mn);
    }
    erfen();
}   
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    freopen("moonmirror.in","r",stdin);
    freopen("moonmirror.out","w",stdout);
    //再慢就删注释，去宏定义（fread、fwrite的宏定义改函数会慢很多）
    //ll T=1;
    //cin>>T;
    //while(T--){
        solve();
    //}
    return 0;
}
/*
string yusiwen=SB,x=and;
string wangzhongyu=maoniang;
wangzhongyu=yusiwen+x+wangzhongyu;
yusiwen.clear();
cout<<"wangzhongyu is "<<wangzhongyu;
*/
//调代码：张bh or HBWT25051 or HBCSP26013 or ZBH2015 or ZBH2025 or zhangbohan
//不给你加我的神秘define了