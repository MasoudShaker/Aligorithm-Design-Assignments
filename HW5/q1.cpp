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
const ll max_k = 30000 + 20;

void glass_cleaner_length_left_update(int_pair rmf, int_pair lrms, int i, int rmfi, int &gcl)
{
    if (rmf.F > lrms.F)
    {
        if (rmf.S - lrms.F - (i - rmfi) > gcl - 1)
        {
            gcl = rmf.S - (i - rmfi) - lrms.F + 1;
        }
    }
}

void glass_cleaner_length_right_update(int_pair rmf, int_pair lrms, int i, int rmfi, int &gcl)
{
    if (rmf.F > lrms.F)
    {
        if (rmf.S - lrms.F - (i - rmfi) > gcl - 1)
        {
            gcl = rmf.S - (i - rmfi) - lrms.F + 1;
        }
    }
}

void left_most_update(int_pair lrms, int_pair &lml, int &lmli, int i){
    if (lrms.F - i < lml.F - lmli)
    {
        lml = lrms;
        lmli = i;
    }
}

void right_most_update(int_pair lrms, int_pair &rmf, int &rmfi, int i){
    if (lrms.S + i > rmf.S + rmfi)
    {
        rmf = lrms;
        rmfi = i;
    }
}

int main()
{
    fastio

    int n, k;
    cin >> n >> k;

    int_pair left_right_most_stain[n];

    forl(i, 0, n)
    {
        left_right_most_stain[i] = mp(-1, -1);
    }

    int glass_cleaner_length = 0;
    int l, r;

    forl(i, 0, k)
    {
        cin >> l >> r;
        l--;
        r--;

        if (left_right_most_stain[l] == mp(-1, -1))
        {
            left_right_most_stain[l] = mp(r, r);
        }
        else
        {
            if (r > left_right_most_stain[l].S)
            {
                left_right_most_stain[l] = mp(left_right_most_stain[l].F, r);
            }

            if (r < left_right_most_stain[l].F)
            {
                left_right_most_stain[l] = mp(r, left_right_most_stain[l].S);
            }

        }
        if (glass_cleaner_length < left_right_most_stain[l].S - left_right_most_stain[l].F + 1)
        {
            glass_cleaner_length = left_right_most_stain[l].S - left_right_most_stain[l].F + 1;
        }
    }

    int l_m_l_i = 0;
    int r_m_f_i = 0;

    int_pair cur_l_r_m_s = mp(-1, -1);
    int_pair left_most_last = mp(-1, -1);
    int_pair right_most_first = mp(-1, -1);

    forl(i, 0, n)
    {
        if (left_right_most_stain[i] != mp(-1, -1))
        {
            if (cur_l_r_m_s == mp(-1, -1))
            {
                cur_l_r_m_s = left_right_most_stain[i];
                left_most_last = left_right_most_stain[i];
                right_most_first = left_right_most_stain[i];
                l_m_l_i = i;
                r_m_f_i = i;
            }
            else
            {
                cur_l_r_m_s = left_right_most_stain[i];

                glass_cleaner_length_left_update(right_most_first, cur_l_r_m_s, i, r_m_f_i, glass_cleaner_length);
                glass_cleaner_length_right_update(right_most_first, cur_l_r_m_s, i, r_m_f_i, glass_cleaner_length);
                int left_most_difference = i - l_m_l_i;
                if (left_most_last.S < cur_l_r_m_s.S)
                {
                    if (cur_l_r_m_s.S - left_most_last.F - left_most_difference > glass_cleaner_length - 1)
                    {
                        glass_cleaner_length = cur_l_r_m_s.S - left_most_difference - left_most_last.F + 1;
                    }
                }

                left_most_update(cur_l_r_m_s, left_most_last, l_m_l_i, i);
                right_most_update(cur_l_r_m_s, right_most_first, r_m_f_i, i);
            }
        }
    }

    cout << glass_cleaner_length << endl;

    return 0;
}