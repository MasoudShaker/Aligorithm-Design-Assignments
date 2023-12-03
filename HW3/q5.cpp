#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <bits/stdc++.h>

using namespace std;

int num_of_longitudinal, num_of_tranverse;

int main()
{
    fastio

    int n, x, y;
    cin >> n >> x >> y;

    if (n <= 0){
        cout << 0 << ' ' << 0;
        return 0;
    }

        if (n % x == 0)
        {
            num_of_longitudinal = n / x;

            cout << num_of_longitudinal << ' ' << num_of_tranverse;
            return 0;
        }

    if (n % y == 0)
    {
        num_of_tranverse = n / y;

        cout << num_of_longitudinal << ' ' << num_of_tranverse;
        return 0;
    }

    while (n > 0)
    {
        n -= x;
        num_of_longitudinal++;
        if (n % y == 0){
            num_of_tranverse = n / y;
            cout << num_of_longitudinal << ' ' << num_of_tranverse;
            return 0;
        }
    }

    cout << -1;
    return 0;
}