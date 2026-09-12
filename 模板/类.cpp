#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
class father{
    public:
        int a;
        double s;
    protected:
        int b;
        father(int x,double y,int z):a(x),s(y),b(z){}
};
class son:public father{
    private:
        bool f;
    public:
    son(int x,double y,int z,bool g):father(x,y,z),f(g){}
};
void solve(){
    son t(10,1.23,100,1);
    cout<<t.s;
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