#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s1,s2,t1,t2,ans;
void solve(){
    cin>>s1>>s2>>t1>>t2;
    if(s1==t1){
        ans.push_back('1');
    }else{
        cout<<"0000";
        return;
    }
    char s3=s2[2],t3=t2[2];
    s2.pop_back();t2.pop_back();
    if(s2==t2) ans.push_back('1');
    else{
        cout<<"1000";
        return;
    }
    for(char i='A';i<='C';i++){
        for(char j='A';j<='C';j++){
            if(j==i) continue;
            if(s3==i&&t3==j){
                ans.push_back('1');
            }
        }
    }
    if(ans.size()==2){
        if((s3=='D'&&t3=='F')||(t3=='D'&&s3=='F')){
            ans.push_back('1');
        }else{
            cout<<"1100";
            return;
        }
    }
    if((s3=='D'&&t3=='F')||(t3=='D'&&s3=='F')){
        ans.push_back('1');
    }else if((s3=='A'&&t3=='B')||(s3=='B'&&t3=='C')){
        ans.push_back('1');
    }else if((t3=='A'&&s3=='B')||(t3=='B'&&s3=='C')){
        ans.push_back('1');
    }else{
        cout<<"1110";
        return;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}