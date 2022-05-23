#include <bits/stdc++.h>
using namespace std;

int G[55][55];
int n, m;

void init();
int prim();

int main()
{
    init();
    cout << prim() << endl;
    return 0;
}

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            G[i][j] = 10000;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        G[x][y] = z;
        G[y][x] = z;
    }
}

int prim()
{
    int ans = 0;
    int visit[55];
    int dis[55];
    memset(visit, 0, sizeof(visit));
    visit[1] = 1;
    for (int i = 1; i <= n; i++)
        dis[i] = G[1][i];
    for (int i = 2; i <= n; i++)
    {
        int min = INT_MAX;
        int index = 0;
        for (int j = 1; j <= n; j++)
            if (!visit[j] && dis[j] < min)
                index = j, min = dis[j];
        visit[index] = 1;
        ans += min;
        for (int j = 1; j <= n; j++)
            if (!visit[j])
                dis[j] = G[index][j] < dis[j] ? G[index][j] : dis[j];
    }
    return ans;
}