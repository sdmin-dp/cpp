#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s,t;  // s: 主串（文本串）, t: 模式串（待查找的字符串）
ll n,m;      // n: 主串s的长度, m: 模式串t的长度
ll nxt[N];   // next数组（部分匹配表），存储模式串每个位置的最长公共前后缀长度

void solve(){
    cin>>s>>t;  // 输入主串s和模式串t
    n=s.size(),m=t.size();  // 计算主串和模式串的长度（注意：这里m应该是t.size()）
    
    // 构建next数组（部分匹配表）
    // next数组含义：next[i]表示模式串t[0..i]这个子串的最长公共前后缀的长度[3,7](@ref)
    for(int i=1,j=0;i<m;i++){  // i从1开始，因为next[0]总是0（单个字符无公共前后缀）
        // 当j>0且当前字符不匹配时，通过next数组回溯j的位置
        // 利用已知信息避免完全从头匹配，这是KMP算法的核心[1,7](@ref)
        while(j>0&&t[i]!=t[j]) j=nxt[j-1];  // 回溯到前一个部分匹配位置
        
        // 如果当前字符匹配，j向前移动
        if(t[i]==t[j]) j++;  // 匹配成功，最长公共前后缀长度增加
        
        nxt[i]=j;  // 记录当前位置的最长公共前后缀长度
    }
    
    // 使用next数组进行主串匹配
    for(int i=0,j=0;i<n;i++){  // i遍历主串，j表示当前已匹配的模式串长度
        // 当j>0且当前字符不匹配时，通过next数组回溯j的位置
        // 这避免了主串指针i的回退，保证线性时间复杂度[7,8](@ref)
        while(j>0&&s[i]!=t[j]) j=nxt[j-1];  // 利用部分匹配信息跳过不必要的比较
        
        // 如果当前字符匹配，j向前移动
        if(s[i]==t[j]) j++;  // 匹配成功，继续比较下一个字符
        
        // 如果完全匹配成功（j等于模式串长度）
        if(j==m){
            cout<<i-m+1<<el;  // 输出匹配起始位置（从0开始计数）
            j=nxt[j-1];  // 继续寻找下一个可能的匹配位置[1](@ref)
        }
    }
}

int main() {
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