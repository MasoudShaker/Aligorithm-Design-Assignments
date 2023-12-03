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
typedef pair<ll, ll> ll_pair;
typedef pair<int, int> int_pair;

const ll max_n = 10000 + 20;

ll_pair ranges[max_n];
ll_pair barare_sets[max_n][max_n];
vector<ll_pair> barare_sets_temp[max_n];
bool is_common = true;
int biggest_barare_liked_set_size[max_n];

bool a_in_b_or_vice_versa(ll_pair a, ll_pair b)
{
    if (a.F >= b.F && a.S <= b.S)
    {
        return true;
    }
    else if (a.F <= b.F && a.S >= b.S)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    fastio

        ll n;
    cin >> n;

    forl(i, 0, n)
    {
        ll a, b;
        cin >> a >> b;

        ranges[i].F = a;
        ranges[i].S = b;
    }

    forl(i, 0, n)
    {
        barare_sets[i][0] = mp(ranges[i].F, ranges[i].S);
    }

    forl(i, 0, n)
    {
        forl(j, i + 1, n)
        {
            if (a_in_b_or_vice_versa(ranges[i], ranges[j]))
            {
                forl(k, 0, j)
                {
                    if (!(barare_sets[i][k].F == 0 && barare_sets[i][k].S == 0))
                    {
                        if (!a_in_b_or_vice_versa(ranges[j], barare_sets[i][k]))
                        {
                            is_common = false;
                            break;
                        }  
                    }
                }
                if (is_common)
                {
                    barare_sets[i][j] = ranges[j];
                }
            }
        }
    }

    forl(i, 0, n){
        forl(j, 0, n){
            if (barare_sets[i][j].F != 0 && barare_sets[i][j].S != 0){
                biggest_barare_liked_set_size[i]++;
            }
        }
    }
    cout << *max_element(biggest_barare_liked_set_size, biggest_barare_liked_set_size + n);
}