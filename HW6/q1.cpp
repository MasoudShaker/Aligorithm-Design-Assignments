#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define forl(i, s, e) for (int i = (int)s; i < (int)e; i++)
#define forld(i, s, e) for (int i = (int)s; i > 0; i--)
#define foreq(i, s, e) for (int i = (int)s; i <= (int)e; i++)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ins insert

#include <bits/stdc++.h>
using namespace std;

ll nima_beyz[30][80][1000 + 20];
ll calculated[30][80][1000 + 20];
ll cu[1000 + 20];
ll ban[1000 + 20];
ll pr[1000 + 20];
bool no_mowz_no_khiar_anyway;
ll ans;

ll min_price_for_nima_to_pay(ll num_of_boxes, ll num_of_cucumbers, ll num_of_bananas)
{
    no_mowz_no_khiar_anyway = num_of_cucumbers <= 0 && num_of_bananas <= 0;

    if (no_mowz_no_khiar_anyway && num_of_boxes < 0)
    {
        return 0;
    }
    else if (num_of_boxes < 0)
    {
        return 1000000 + 20;
    }
    else
    {
        if (num_of_bananas < 0)
        {
            num_of_bananas = 0;
        }
        if (num_of_cucumbers < 0)
        {
            num_of_cucumbers = 0;
        }
        if (calculated[num_of_bananas][num_of_cucumbers][num_of_boxes])
        {
            return nima_beyz[num_of_bananas][num_of_cucumbers][num_of_boxes];
        }
        calculated[num_of_bananas][num_of_cucumbers][num_of_boxes] = true;
        nima_beyz[num_of_bananas][num_of_cucumbers][num_of_boxes] = min(min_price_for_nima_to_pay(num_of_boxes - 1, num_of_cucumbers, num_of_bananas), min_price_for_nima_to_pay(num_of_boxes - 1, num_of_cucumbers - cu[num_of_boxes], num_of_bananas - ban[num_of_boxes]) + pr[num_of_boxes]);
        return nima_beyz[num_of_bananas][num_of_cucumbers][num_of_boxes];
    }
}

int main()
{
    ll c;
    cin >> c;

    forl(i, 0, c)
    {
        ll x;
        ll y;
        ll n;
        cin >> x >> y >> n;

        foreq(m, 0, x)
        {
            foreq(g, 0, y)
            {
                foreq(h, 0, n)
                {
                    calculated[m][g][h] = false;
                }
            }
        }

        forl(j, 0, n)
        {
            cin >> ban[j] >> cu[j] >> pr[j];
        }

        ans = min_price_for_nima_to_pay(n - 1, y, x);
        
        cout << ans << endl;
    }
}
