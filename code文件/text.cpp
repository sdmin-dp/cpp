#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pll pair<ll, ll>
#define el '\n'
const ll N = 2e6 + 5;
const ll mod = 19930726;
string s;
ll n, k, ans = 1;
int p[N], d[N], m;
ll qpow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b % 2==1)
			res = res * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return res;
}
void manacher()
{
	int M = 0, R = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < R)
		{
			int k = 2 * M - i;
			p[i] = min(R - i, p[k]);
		}
		int left = i - (1 + p[i]), right = i + (1 + p[i]);
		while (left >= 0 && right < n && s[left] == s[right])
		{
			p[i]++;
			left--;
			right++;
		}
		if (i + p[i] - 1 > R)
			M = i, R = i + p[i] - 1;
	}
}
void solve()
{
	cin >> n >> k;
	cin >> s;
	manacher();
	for (int i = 0; i < n; i++)
	{
		p[i] = 2 * p[i] + 1;
		d[1]++, d[p[i] / 2 + 2]--;
		m = max(m, p[i] / 2 + 2);
	}
	for (int i = 1; i <= m; i++)
	{
		d[i] += d[i - 1];
	}
	for (int i = m; i > 0; i--)
	{
		if (k >= d[i])
			ans = ans * qpow(2 * i - 1, d[i]) % mod, k -= d[i];
		else
		{
			ans = ans * qpow(2 * i - 1, k)%mod, k = 0;
			cout << ans;
			return;
		}
	}
	cout << "-1";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("xxx.in","r",stdin);
	// freopen("xxx.out","w",stdout);
	ll T = 1; // cin>>T;
	while (T--)
	{
		solve();
	}
	return 0;
}