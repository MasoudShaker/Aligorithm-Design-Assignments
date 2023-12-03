#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define forl(i, s, e) for (int i = (int)s; i < (int)e; i++)
#define foreq(i, s, e) for (int i = (int)s; i <= (int)e; i++)
#define mp make_pair
#define pb push_back
#define F first
#define S second

#include <bits/stdc++.h>

using namespace std;

const ll max_n = 10000 + 20;

int p, q, r, s, t, u;

double low = 0, high = 1;

string no_ans = "No solution";

double cute_func(double x)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double derivative_cute_func(double x)
{
    return -p * exp(-x) + q * cos(x) - r * sin(x) + s / (cos(x) * cos(x)) + 2 * t * x;
}

double cute_newton()
{
    if (cute_func(0) == 0)
    {
        return 0;
    }

    for (double x = 0.5;;)
    {
        double x_t = x - cute_func(x) / derivative_cute_func(x);
        if (fabs(x_t - x) < exp(-20))
        {
            return x;
        }

        x = x_t;
    }
}

int main()
{
    cin >> p >> q >> r >> s >> t >> u;
    if (cute_func(0) * cute_func(1) > 0)
    {
        cout << no_ans << endl;
        ;
    }
    else
    {
        cout << round(cute_newton() * 10000.0) / 10000.0 << endl;
    }
}