#include<bits/stdc++.h>
using namespace std;
#define ll long long
char ch[200005];
ll gs;
bool re[200005];
ll where[200005];
int main()
{
    //freopen("mirror.in","r",stdin);
    //freopen("mirror.out","w",stdout);
    ll n,k;
    cin>>n>>k;
    cin>>ch;
    for(int i=0;i<n/2;i++)
    {
        int j=n-i-1;
        if(ch[i]!=ch[j])
        {
            where[gs++]=i;
            //cout<<ch[i]<<' '<<ch[j]<<endl;
        }
    }

    if(gs>k){cout<<-1;return 0;}
    if(gs==k){
        for(int i=0;i<gs;i++)
        {
            //ll x=(long long)(ch[where[i]]-'0');
            //ll y=(long long)(ch[where[n-i-1]]-'0');
            //cout<<x<<' '<<y<<endl;
            char x=ch[where[i]];
            char y=ch[n-where[i]-1];
            if(x-y>0)
            {
                ch[n-where[i]-1]=ch[where[i]];
                k--;
            }
            else if(x-y<0)
            {
                k--;
                ch[where[i]]=ch[n-where[i]-1];
            }
        }
        cout<<ch;
        return 0;
    }
    if(gs<k)
    {
        for(int i=0;i<gs;i++)
        {
            //ll x=(long long)(ch[where[i]]-'0');
            //ll y=(long long)(ch[where[n-i-1]]-'0');
            //cout<<x<<' '<<y<<endl;
            char x=ch[where[i]];
            char y=ch[n-where[i]-1];
            if(x-y>0)
            {
                ch[n-where[i]-1]=ch[where[i]];
                k--;
                re[where[i]]=1;   
            }
             else if(x-y<0)
            {
                k--;
                ch[where[i]]=ch[n-where[i]-1];
                re[where[i]]=1;
            }

        }
        //die dai shuang *
        if(k%2)
        {
            if(n%2)ch[n/2]='9',k--;

        }
        for(int i=0;i<n/2;i++)
        {
            if(re[i]&&k){
                k--;
                ch[i]='9';
                ch[n-i-1]='9';
            }
        }
        if(k==0)
        {
            cout<<ch;
            return 0;
        }
        else if(k==1)
        {
            ch[n/2]='9';
        }
        for(int i=0;i<n/2;i++)
        {
            if(ch[i]!='9'&&k>=2)
            {
                k-=2;
                ch[i]=ch[n-i-1]='9';
            }
        }
        cout<<ch;
    }
    return 0;
}