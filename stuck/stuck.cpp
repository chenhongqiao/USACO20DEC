#include <bits/stdc++.h>
using namespace std;
struct cow
{
    char d;
    int x, y;
};
struct react
{
    int a, b;
    int t;
};
vector<cow> c;
vector<react> r;
bool comp(react a, react b)
{
    return a.t < b.t;
}
int ans[1005] = {0};
int st[1005];
int sb[1005];
void trans(int a, int v)
{
    ans[a] += v;
    if (sb[a] != -1)
    {
        trans(sb[a], v);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char d;
        int x, y;
        cin >> d >> x >> y;
        c.push_back({d, x, y});
    }
    for (int i = 0; i < n; i++)
    {
        st[i] = 1000000005;
        sb[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (c[i].d == c[j].d)
            {
                continue;
            }
            int tmp = max(abs(c[i].x - c[j].x), abs(c[i].y - c[j].y));
            r.push_back({i, j, tmp});
        }
    }
    sort(r.begin(), r.end(), comp);
    for (int i = 0; i < r.size(); i++)
    {
        int a = r[i].a;
        int b = r[i].b;
        if (c[a].d == 'N' && c[a].x > c[b].x && c[a].y < c[b].y)
        {
            if (c[b].y - c[a].y < c[a].x - c[b].x)
            {
                if (st[a] > c[b].y - c[a].y && st[b] > c[a].x - c[b].x)
                {
                    st[b] = c[a].x - c[b].x;
                    sb[b] = a;
                    trans(a, ans[b] + 1);
                }
            }
            else if (c[b].y - c[a].y > c[a].x - c[b].x)
            {
                if (st[a] > c[b].y - c[a].y && st[b] > c[a].x - c[b].x)
                {
                    st[a] = c[b].y - c[a].y;
                    sb[a] = b;
                    trans(b, ans[a] + 1);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}