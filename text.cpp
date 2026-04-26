#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll A,B,C,a,b,c;
ll cnt1,cnt2,id1,id2,mn1,mn2;
unordered_set<ll> st;
ll rehash(ll x){
    ll p1=x/10000,p2=x%10000,p3=C-p1-p2;
    return min({p1,p2,p3});
}
void solve(){
    cin>>A>>B>>C;
    a=b=0;c=C;
    while(st.find(a*10000+b)==st.end()){
        if(b==0){
            if(c<B) b=c,c=0;
            else if(c>=B) b=B,c-=B;
        }else if(a==A){
            c+=a;
            a=0;
        }else{
            if(A-a>=b) a+=b,b=0;
            else if(A-a<b) b-=(A-a),a=A;
        }
        st.insert(a*10000+b);
    }
    ll j=0;
    for(auto i:st){
        j++;
        if(rehash(i)<mn1){
            id1=j;
            mn1=i;
        }
    }
    swap(A,B);
    a=0,b=0,c=C;
    st.clear();
    while(st.find(a*10000+b)==st.end()){
        if(b==0){
            if(c<B) b=c,c=0;
            else if(c>=B) b=B,c-=B;
        }else if(a==A){
            c+=a;
            a=0;
        }else{
            if(A-a>=b) a+=b,b=0;
            else if(A-a<b) b-=(A-a),a=A;
        }
        st.insert(a*10000+b);
    }
    j=0;
    for(auto i:st){
        j++;
        if(rehash(i)<mn2){
            id2=j;
            mn2=i;
        }
    }
    if(mn1<mn2) cout<<mn1<<el<<id1;
    else if(mn1>mn2) cout<<mn2<<" "<<id2;
    else cout<<mn1<<" "<<min(id1,id2);
}
int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}