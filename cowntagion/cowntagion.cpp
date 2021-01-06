#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
long long ans = 0;
bool v[100005];
void dfs(int f)
{
    long long k = 1;
    int s = 0;
    for (int i = 0; i < g[f].size(); i++)
    {
        if (!v[g[f][i]])
        {
            s++;
        }
    }

    while (k < s + 1)
    {
        k *= 2;
        ans++;
    }
    for (int i = 0; i < g[f].size(); i++)
    {
        if (!v[g[f][i]])
        {
            v[g[f][i]] = true;
            ans++;
            dfs(g[f][i]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    v[1] = true;
    dfs(1);
    cout << ans << endl;
    return 0;
}