#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> p;
int g[2505][2505];
int sum[2505][2505];
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++)
    {
        p[i].first = i + 1;
    }
    sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        p[i].second = i + 1;
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++)
    {
        g[p[i].first][p[i].second] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + g[i][j];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans++;
        for (int j = i + 1; j < n; j++)
        {
            int t = min(p[i].second, p[j].second);
            int b = max(p[i].second, p[j].second);
            long long tn = sum[p[j].first][t] - sum[p[i].first - 1][t];
            long long bn = sum[p[j].first][n] - sum[p[i].first - 1][n] - sum[p[j].first][b - 1] + sum[p[i].first - 1][b - 1];
            ans += (tn * bn);
        }
    }
    cout << ans + 1 << endl;

    return 0;
}