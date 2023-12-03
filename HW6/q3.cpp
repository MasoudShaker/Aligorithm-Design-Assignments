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
#define ins insert

#include <bits/stdc++.h>
using namespace std;

long long knight_move[100 + 20][100 + 20][100 + 20];
bool seen[100 + 20][100 + 20][100 + 20];
ll calculate_sum(ll x1, ll y1, ll k, ll x2, ll y2, ll n, ll &s);
ll min_num_of_horse_moves(ll x1, ll y1, ll k, ll x2, ll y2, ll n, ll s);

int main()
{
    ll n;
    ll k;
    cin >> n >> k;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    cout << min_num_of_horse_moves(x1, y1, k, x2, y2, n, 0) << endl;
}
ll min_num_of_horse_moves(ll x1, ll y1, ll k, ll x2, ll y2, ll n, ll s)
{
    s = 0;
    if (seen[x1][y1][k])
    {
        return knight_move[x1][y1][k];
    }
    if (k == 0)
    {
        if (x1 == x2 && y1 == y2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    seen[x1][y1][k] = true;
    return knight_move[x1][y1][k] = calculate_sum(x1, y1, k, x2, y2, n, s) % 1000000007;
}
ll calculate_sum(ll x1, ll y1, ll k, ll x2, ll y2, ll n, ll &s)
{

    ll x_coordinates[] = {2, 1, -1, -2, -2, -1, 1, 2};
    ll y_coordinates[] = {1, 2, 2, 1, -1, -2, -2, -1};
    forl(i, 0, 8)
    {
        ll new_x1 = x1 + x_coordinates[i];
        ll new_y1 = y1 + y_coordinates[i];

        if (new_x1 >= 0 && new_x1 < n && new_y1 >= 0 && new_y1 < n)
        {
            s += min_num_of_horse_moves(new_x1, new_y1, k - 1, x2, y2, n, s);
        }
    }
    return s;
}