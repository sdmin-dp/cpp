#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
unordered_set<int> st;
void solve()
{
    ll a, b, c, ax = 0, bx = 0, cx, ans1 = 0, ans, minx, type = 0;
    cin >> a >> b >> c;
    cx = minx = c;
    while (type < 2)
    {
        if (type == 0)
        {
            ll k = min(b, cx);
            bx += k;
            cx -= k;
            ans1++;
            if (bx && (bx < minx || bx == minx && ans1 < ans))
                minx = bx, ans = ans1;
            if (ax && (ax < minx || ax == minx && ans1 < ans))
                minx = ax, ans = ans1;
            if (cx && (cx < minx || cx == minx && ans1 < ans))
                minx = cx, ans = ans1;
            if (st.find(ax * 5000 + bx) == st.end())
            {
                st.insert(ax * 5000 + bx);
            }
            else
                type = 2;
            if (type == 0)
                type = 1;
        }
        else if (type == 1)
        {
            if (bx > 0)
            {
                if (ax == a)
                    cx += ax, ax = 0;
                else if (bx >= a - ax)
                    bx -= a - ax, ax = a;
                else
                    ax += bx, bx = 0;
            }
            ans1++;
            if (bx && (bx < minx || bx == minx && ans1 < ans))
                minx = bx, ans = ans1;
            if (ax && (ax < minx || ax == minx && ans1 < ans))
                minx = ax, ans = ans1;
            if (cx && (cx < minx || cx == minx && ans1 < ans))
                minx = cx, ans = ans1;
            if (st.find(ax * 5000 + bx) == st.end())
            {
                st.insert(ax * 5000 + bx);
            }
            else
                type = 2;
            if (type == 1 && bx == 0)
                type = 0;
        }
    }
    swap(a, b);
    st.clear();
    type = ax = bx = ans1 = 0;
    cx = c;
    if (a == b && b == c)
    {
        cout << a << "\n0";
        return;
    }
    while (type < 2)
    {
        if (type == 0)
        {
            ll k = min(b, cx);
            bx += k;
            cx -= k;
            ans1++;
            if (bx && (bx < minx || bx == minx && ans1 < ans))
                minx = bx, ans = ans1;
            if (ax && (ax < minx || ax == minx && ans1 < ans))
                minx = ax, ans = ans1;
            if (cx && (cx < minx || cx == minx && ans1 < ans))
                minx = cx, ans = ans1;
            if (st.find(ax * 5000 + bx) == st.end())
            {
                st.insert(ax * 5000 + bx);
            }
            else
                type = 2;
            if (type == 0)
                type = 1;
        }
        else if (type == 1)
        {
            if (bx > 0)
            {
                if (ax == a)
                    cx += ax, ax = 0;
                else if (bx >= a - ax)
                    bx -= a - ax, ax = a;
                else
                    ax += bx, bx = 0;
            }
            ans1++;
            if (bx && (bx < minx || bx == minx && ans1 < ans))
                minx = bx, ans = ans1;
            if (ax && (ax < minx || ax == minx && ans1 < ans))
                minx = ax, ans = ans1;
            if (cx && (cx < minx || cx == minx && ans1 < ans))
                minx = cx, ans = ans1;
            if (st.find(ax * 5000 + bx) == st.end())
            {
                st.insert(ax * 5000 + bx);
            }
            else
                type = 2;
            if (type == 1 && bx == 0)
                type = 0;
        }
    }
    cout << minx << '\n' << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(0);

    int T = 1; // cin >> T;
    while (T--)
        solve();

    return 0;
}