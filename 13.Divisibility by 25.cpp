#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
string n,m,s[4]={"00","25","50","75"};
ll ans=1e9,cnt;

void solve(){
    cin>>n;
    for(int i=0;i<4;i++){
        m=n;
        cnt=0;
        bool flag[2]={0,0};
        for(int j=1;j>=0;j--){
            for(int k=m.size()-1;k>=0;k--){
                if(m[k]==s[i][j]){
                    cnt+=m.size()-1-k;
                    m.erase(k,1);
                    flag[j]=1;
                    break;
                }
            }
        }
        if(!m.empty()&&m[0]=='0'){
            for(int k=0;k<m.size();k++){
                if(m[k]!='0'){
                    cnt+=k;
                    break;
                }
            }
        }
        if(flag[0]==1&&flag[1]==1){
            ans=min(ans,cnt);
        }
    }
    cout<<(ans==1e9?-1:ans);
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