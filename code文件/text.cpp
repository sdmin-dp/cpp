#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[200005],a[200005];
signed main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for(int i=1;i<=n;i++) dp[i]=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?') a[i+1]=-1;
            else a[i+1]=s[i]-'0';
        }
        int cnt=0;
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(i>2) 
                {
                    if(a[i-2]!=-1 && a[i-2]==a[i])
                    {
                        cout << 0 << endl;
                        flag=1;
                        break;
                    }a[i-2]=1;
                }
                if(i+2<=n) 
                {
                    if(a[i+2]!=-1 && a[i+2]==a[i])
                    {
                        cout << 0 << endl;
                        flag=1;
                        break;
                    }a[i+2]=1;
                }
            }
            if(a[i]==1)
            {
                if(i>2) 
                {
                    if(a[i-2]!=-1 && a[i-2]==a[i])
                    {
                        cout << 0 << endl;
                        flag=1;
                        break;
                    }a[i-2]=0;
                }
                if(i+2<=n) 
                {
                    if(a[i+2]!=-1 && a[i+2]==a[i])
                    {
                        cout << 0 << endl;
                        flag=1;
                        break;
                    }a[i+2]=0;
                }
            }
        }
        if(flag) continue;
        for(int i=1;i<=n;i++)
            cout << a[i] << " ";
        cout << endl;
        if(a[1]!=-1) dp[1]=1;
        else dp[1]=2;
        for(int i=2;i<=n;i++)
        {
            if(i==2)
            {
                if(a[i]!=-1) 
                {
                    if(a[i-1]==a[i+1] && a[i-1]!=-1 && i<n)
                        dp[i]=0;
                    else
                        dp[i]=dp[i-1];
                }
                else
                {
                    if(a[i-1]==a[i+1] && a[i-1]!=-1 && i<n)
                        dp[i]=0;
                    else
                    {
                        if(i<=2)
                        {
                            dp[i]=dp[i-1]*2;
                        }
                        else dp[i]=dp[i-1];
                    }
                        
                        
                }
            }
            else if(i==3)
            {
                if(a[i]!=-1) 
                {
                    if((a[i-1]==a[i+1] && a[i-1]!=-1 && i<n) || (a[i-2]!=a[i+2] && a[i-2]!=-1 && a[i+2]!=-1 && i+2<=n))
                        dp[i]=0;
                    else
                        dp[i]=dp[i-1];
                }
                else
                {
                    if((a[i-1]==a[i+1] && a[i-1]!=-1 && i<n) || (a[i-2]!=a[i+2] && a[i-2]!=-1 && a[i+2]!=-1 && i+2<=n))
                        dp[i]=0;
                    else
                    {
                        if(i<=2)
                            dp[i]=dp[i-1]*2;
                        else dp[i]=dp[i-1];
                    }
                }
            } 
            else
            {
                if(a[i]!=-1) 
                {
                    if((a[i-1]==a[i+1] && a[i-1]!=-1 && i<n) || (a[i-2]!=a[i+2] && a[i-2]!=-1 && a[i+2]!=-1 && i+2<=n))
                        dp[i]=0;
                    else
                        dp[i]=dp[i-1];
                }
                else
                {
                    if((a[i-1]==a[i+1] && a[i-1]!=-1 && i<n) || (a[i-2]!=a[i+2] && a[i-2]!=-1 && a[i+2]!=-1 && i+2<=n))
                        dp[i]=0;
                    else
                    {
                        if(cnt<2)
                            dp[i]=dp[i-1]*2;
                        else dp[i]=dp[i-1];
                    }
                }
            }
        }
        cout << dp[n] << endl;
    } 
     return 0;
}
//0?????1
//0?1?0?1
// 0 1 0
// 1 0 1
// 
//0011001
//0110011
