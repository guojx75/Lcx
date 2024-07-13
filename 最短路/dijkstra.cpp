#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 2147483647;
int cnt = 0;
int n, m, s;
int head[maxn], vis[maxn], dis[maxn];
struct Edge
{
    int u, v, w, next;
} e[5 * maxn];
struct node
{
    int w, now;
    inline bool operator<(const node &x) const
    {
        return w > x.w;
    }
};
priority_queue<node> q;

inline void add(int u, int v, int w)
{
    e[++cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dijkstra()
{
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[s] = 0;
    q.push((node){0, s});
    while (!q.empty())
    {
        node temp = q.top();
        q.pop();
        int u = temp.now;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                q.push((node){dis[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        add(x1, x2, x3);
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << ' ';
    }

    return 0;
}