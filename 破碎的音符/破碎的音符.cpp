#include <iostream>
#include <queue>
#define v first
#define w second
using namespace std;
typedef long long LL;
priority_queue<pair<int, bool>> q;
int n;

void solve()
{
    cin >> n;
    long long sum = 0;
    q = priority_queue<pair<int, bool>>();
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q.push(make_pair(-x, i != 1 && i != n));
    }
    while (q.size() > 2)
    {
        auto a = q.top();
        q.pop();
        auto b = q.top();
        q.pop();
        if (a.w && b.w)
        {
            auto c = q.top();
            q.pop();
            q.push(b);
            b = c;
        }
        int num = a.v + b.v;
        sum += num;
        q.push(make_pair(num, a.w && b.w));
    }
    auto a = q.top();
    q.pop();
    auto b = q.top();
    q.pop();
    sum += a.v + b.v;
    cout << -sum << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
