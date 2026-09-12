#include<bits/stdc++.h>
using namespace std;
int a[15]={0,1,6,2,4,5},n=5;
//vector<int> v(a+1,a+n+1);
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
//	string s;
//	cin>>s;
//	sort(s.begin(),s.end());
//	cout<<s<<endl;
//	sort(v.begin(),v.end());
//	for(int i=1;i<=n;i++)
//		cout<<v[i]<<" ";
//	cout<<endl;
	sort(a+1,a+n+1);
//	for(int i=0;i<n;i++) cout<<a[i]<<" ";
//	int x;
//	cin>>x;
//	cout<<binary_search(a+1,a+n+1,x)<<endl;
//	int k=lower_bound(a+1,a+n+1,x) -a;//第一个大于x的位置 
//	if(k==n+1) cout<<"qazwsxedcrfvtgbyhnujmik,ol.";
//	else cout<<a[k]<<endl;
//	k=upper_bound(a+1,a+n+1,x)-a;//第一个大于等于x的位置 
//	if(k!=0&&a[k-1]==x) 
//	{
//		cout<<"[]';;..]''"<<endl;
//		cout<<upper_bound(a+1,a+n+1,x)-lower_bound(a+1,a+n+1,x);
//	}
	int ans=0;
	do
	{
		for(int i=1;i<=n;i++) cout<<a[i]<<" "; 
		cout<<endl;
		ans++;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}

