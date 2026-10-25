#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s;
vector<string> ans;
stringstream ss;
void solve(){
    getline(cin,s);
    ss<<s;
    while(ss>>s){
        if(!(s[0]>='0'&&s[0]<='9')){
            for(auto &i:s){
                if('A'<=i&&i<='Z'){
                    i=i-'A'+'a';
                }else{
                    i=i-'a'+'A';
                }
            }
        }else{
            reverse(s.begin(),s.end());
        }
        ans.push_back(s);
    }
    reverse(ans.begin(),ans.end());
    for(auto &i:ans){
        cout<<i<<" ";
    }
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