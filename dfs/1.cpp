#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int xDA, yDA, n;
int xStart, ystart, xEnd, yEnd;
int ans = 0;

int isfangwen[100][100];
int zhangai[100][100];

void dfs(int x, int y)
{
    if (x == xEnd && y == yEnd)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int xxx = x + dx[i];
        int yyy = y + dy[i];
        if (xxx >= 1 && xxx <= xDA && yyy <= yDA && yyy >= 1)
        {
            if (!isfangwen[xxx][yyy] && !zhangai[xxx][yyy])
            {
                isfangwen[x][y] = 1;
                dfs(xxx, yyy);
                isfangwen[x][y] = 0;
            }
        }
    }
}

int main()
{

    memset(isfangwen, 0, sizeof(isfangwen));
    memset(zhangai, 0, sizeof(zhangai));

    cin >> xDA >> yDA >> n;
    cin >> xStart >> ystart >> xEnd >> yEnd;
    for (int i = 0; i < n; i++)
    {
        int xtemp;
        int ytemp;
        cin >> xtemp >> ytemp;
        zhangai[xtemp][ytemp] = 1;
    }

    dfs(xStart, ystart);
    cout << ans << endl;

    return 0;
}