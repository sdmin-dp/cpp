/**
 * 扩展KMP算法（Z-Algorithm）
 * 
 * 算法功能：
 * 计算字符串s的Z数组，其中z[i]表示从位置i开始的后缀与原字符串s的最长公共前缀(LCP)长度
 * 即: z[i] = max{ k | s[1..k] == s[i..i+k-1] }
 * 
 * 时间复杂度: O(n)，利用之前计算的信息避免重复比较
 * 空间复杂度: O(n)
 * 
 * 核心思想：
 * 维护一个区间[l, r]，表示当前找到的最右匹配区间，即s[l..r] == s[1..r-l+1]
 * 对于新位置i，利用对称性快速初始化z[i]，然后暴力扩展
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;

string s;      // 输入字符串
ll n;          // 字符串长度
ll z[N];       // Z数组，z[i]表示从位置i开始的后缀与原串的最长公共前缀长度
ll l=1, r;     // 维护的最右匹配区间[l, r]，满足s[l..r] == s[1..r-l+1]

void solve(){
    cin>>s;
    n=s.size();
    s=' '+s;   // 字符串下标从1开始，方便处理
    
    // 从第2个位置开始计算（z[1]默认为n）
    for(int i=2;i<=n;i++){
        // 情况1: i在当前最右匹配区间之外，无法利用对称性，从头开始匹配
        if(i>r){
            z[i]=0;
        }else{
            // 情况2: i在区间内，利用对称性快速初始化
            // i在[l, r]内，其对称点为 k = i - l + 1
            // 根据对称性，s[i..i+z[k]-1] == s[k..k+z[k]-1] == s[1..z[k]]
            // 但不能超过r-i+1，因为r之后的信息未知
            ll k=i-l+1;           // 对称点位置
            z[i]=min(z[k], r-i+1);
        }
        
        // 暴力扩展：从当前已知长度开始，继续向后匹配
        while(i+z[i]<=n && s[z[i]+1]==s[i+z[i]]) z[i]++;
        
        // 更新最右匹配区间
        // 如果新的匹配范围超过了当前r，则更新l和r
        if(i+z[i]-1>r) l=i, r=i+z[i]-1;
    }
    
    // 输出Z数组的最大值（即最长公共前缀长度）
    ll ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,z[i]);
    cout<<ans;
    for(int i=1;i<=n;i++) cerr<<z[i]<<" ";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}