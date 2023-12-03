#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define li long int

#define pb push_back

#include <bits/stdc++.h>

using namespace std;

const li max_n = 100000000 + 20;

li ps[max_n];

li ans;

set<li> cumulative_set;

int main()
{
    fastio

    int n;
    cin >> n;

    li h;
    cin >> h;

    for (int i = 0; i < n; i++)
    {
        li p;
        cin >> p;

        ps[i] = p;
    }

    cumulative_set.insert(0);

    li cumulative_sum = 0;

    for (int i = 0; i < n; i++)
    {
        cumulative_sum += ps[i];

        set<li>::iterator set_iterator = cumulative_set.lower_bound(cumulative_sum - h);

        if (set_iterator != cumulative_set.end())
        {
            ans = max(ans, cumulative_sum - *set_iterator);
        }

        cumulative_set.insert(cumulative_sum);
    }

    if (ans < 0)
    {
        ans = 0;
    }

    cout << ans << endl;

    return 0;
}
