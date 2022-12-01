#include <iostream>
#include <queue>
#include <fstream>
#include <ctime>
#define v first
#define w second
using namespace std;
typedef long long LL;
priority_queue<pair<int, bool>> q;
int n;

int random(int n)
{
	return (long long)rand()*rand()%n;
}
ofstream ffin("C:\\Users\\65444\\Desktop\\in\\1.in");
ofstream ffout("C:\\Users\\65444\\Desktop\\in\\1.out");
    
    

void solve()
{
	
    n=random(10000);
    ffin<<n<<endl;
    long long sum = 0;
    q = priority_queue<pair<int, bool>>();
    for (int i = 1; i <= n; i++)
    {
        int x=random(1000000000);
        ffin<< x<<' ';
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
    ffout << -sum << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand((unsigned)time(0));
    
    int t=5;
    ffin<<t<<endl;
    while (t--)
        solve();
    return 0;
}

