#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define lli long long int
#define li long int

#include <bits/stdc++.h>

using namespace std;

const lli max_n = 10000000 + 20;

li num_of_weekly_schedules[max_n];

struct student
{
    int l, r, t;

    bool operator<(student const &other_std)
    {
        return r < other_std.r;
    }
};

student s[max_n];

int sum_ans;

int sum;
int sum_l_to_r_i;

int main()
{
    fastio

    li n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        li r, l, t;

        cin >> l;
        s[i].l = l;

        cin >> r;
        s[i].r = r;

        cin >> t;
        s[i].t = t;

        if (n == 1 && m == 1)
        {
            cout << t << endl;
            return 0;
        }
    }

    sort(s, s + m);

    num_of_weekly_schedules[s[0].r - 1] = s[0].t;

    for (int i = 1; i < m; i++)
    {
        if (((s[i].l >= s[i - 1].l) && (s[i].l <= s[i - 1].r)) || ((s[i].l <= s[i - 1].l)))
        {
            sum_l_to_r_i = accumulate(num_of_weekly_schedules + s[i].l - 1, num_of_weekly_schedules + s[i].r, sum);

            if (s[i].t > sum_l_to_r_i)
            {
                num_of_weekly_schedules[s[i].r - 1] += s[i].t - sum_l_to_r_i;
            }
        }
        else
        {
            num_of_weekly_schedules[s[i].r - 1] = s[i].t;
        }
    }

    sum_ans = accumulate(num_of_weekly_schedules, num_of_weekly_schedules + n, sum);

    cout << sum_ans << endl;

    return 0;
}
