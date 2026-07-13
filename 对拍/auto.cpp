#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
void solve(){
    cout<<"请输入想运行的测试样例组数:";
    cin>>n;
    system("g++ -std=c++14 -O2 ac.cpp -o ac.exe");
    system("g++ -std=c++14 -O2 baoli.cpp -o baoli.exe");
    system("g++ -std=c++14 -O2 gen.cpp -o gen.exe");
    for(int i=1;i<=n;i++){
        system("gen.exe");
        system("ac.exe");
        system("baoli.exe");
        if(system("fc output1.out output2.out")){
            cout<<"发现错误,请查看input和output文件";
            break;
        }
    }
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