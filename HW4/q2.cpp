#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define ll long long 

#define F first
#define S second

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100000 + 20;

pair<int, int> coefficients[max_n];

int ans[max_n];

void calculate_coefficients(int n)
{
    coefficients[1].F = 1;
    coefficients[1].S = 0;

    coefficients[2].F = 0;
    coefficients[2].S = 1;

    for (int i = 3; i <= n; i++)
    {
        coefficients[i].F = (coefficients[i - 1].F + coefficients[i - 2].F) % 1000000007;
        coefficients[i].S = (coefficients[i - 1].S + coefficients[i - 2].S) % 1000000007;
    }
}

int main()
{
    fastio

    ll q;
    cin >> q;

    ll d1, d2, n;

    pair<pair<int, int>, int> d1s_and_d2s_and_ns[max_n];
    priority_queue<int> ns;

    for (int i = 0; i < q; i++)
    {
        cin >> d1;
        d1s_and_d2s_and_ns[i].F.F = d1;

        cin >> d2;
        d1s_and_d2s_and_ns[i].F.S = d2;

        cin >> n;

        if (n == 1)
        {
            ans[i] = d1;
            continue;
        }

        else if (n == 2){
            ans[i] = d2;
            continue;
        }

        else{
            d1s_and_d2s_and_ns[i].S = n;
            ns.push(n);
        }
    }

    calculate_coefficients(ns.top());

    for (int i = 0; i < q; i++)
    {
        ll current_n = d1s_and_d2s_and_ns[i].S;
        ll current_d1 = d1s_and_d2s_and_ns[i].F.F;
        ll current_d2 = d1s_and_d2s_and_ns[i].F.S;

        if (ans[i] == 0){
            ans[i] = (coefficients[current_n].F * current_d1 + coefficients[current_n].S * current_d2) % 1000000007;
        }

        cout << ans[i] << endl;
    }

    return 0;
}