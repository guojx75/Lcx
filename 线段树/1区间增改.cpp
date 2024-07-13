#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll a[maxn];
struct justAtree
{
    int l;
    int r;
    ll sum;
    ll add;
} arr[4 * maxn];

void buidTree(int p, int l, int r)
{
    arr[p].l = l, arr[p].r = r;
    if (l == r)
    {
        arr[p].sum = a[l];
        return;
    }
    else
    {
        int mid = (l + r) >> 1;
        int ls = p * 2;
        int rs = p * 2 + 1;
        buidTree(ls, l, mid);
        buidTree(rs, mid + 1, r);
        arr[p].sum = arr[ls].sum + arr[rs].sum;
    }
}

void downDate(int p)
{
    if (arr[p].add)
    {
        int ls = p << 1;
        int rs = ls + 1;
        arr[ls].sum += arr[p].add * (arr[ls].r - arr[ls].l + 1);
        arr[rs].sum += arr[p].add * (arr[rs].r - arr[rs].l + 1);
        arr[ls].add += arr[p].add;
        arr[rs].add += arr[p].add;
        arr[p].add = 0;
    }
}

ll giveMeAnswer(int p, int l, int r)
{
    if (l <= arr[p].l && arr[p].r <= r)
        return arr[p].sum;
    downDate(p);
    int mid = (arr[p].l + arr[p].r) >> 1;
    int ls = p << 1;
    int rs = ls + 1;
    ll summ = 0;
    if (l <= mid)
        summ += giveMeAnswer(ls, l, r);
    if (r >= mid + 1)
        summ += giveMeAnswer(rs, l, r);
    return summ;
}

void change(int p, int l, int r, int x)
{
    if (l <= arr[p].l && arr[p].r <= r)
    {
        arr[p].sum += x * (arr[p].r - arr[p].l + 1);
        arr[p].add += x;
        return;
    }
    downDate(p);
    int mid = (arr[p].l + arr[p].r) >> 1;
    int ls = p << 1;
    int rs = ls + 1;
    if (l <= mid)
        change(ls, l, r, x);
    if (r >= mid + 1)
        change(rs, l, r, x);
    arr[p].sum = arr[ls].sum + arr[rs].sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int number, asd;
    cin >> number >> asd;
    for (int i = 1; i <= number; i++)
        cin >> a[i];
    buidTree(1, 1, number);
    while (asd--)
    {
        int option;
        cin >> option;
        if (option == 1)
        {
            int lll, x, rrr;
            cin >> lll >> rrr >> x;
            change(1, lll, rrr, x);
        }
        else if (option == 2)
        {
            int lll, rrr;
            cin >> lll >> rrr;
            cout << giveMeAnswer(1, lll, rrr) << endl;
        }
    }

    return 0;
}
