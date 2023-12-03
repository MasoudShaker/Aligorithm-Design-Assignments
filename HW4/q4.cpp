// #define fastio                        \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL);

#include <bits/stdc++.h>

using namespace std;

const int max_n = 30000 + 61;

int ps[max_n];

int dragon_arr[max_n][8920];

int max_pos = 0;

int visited[max_n][8920];

int dragon(int last_jump, int cur_pos)
{
    if (visited[last_jump][cur_pos])
    {
        return dragon_arr[last_jump][cur_pos];
    }
    if (cur_pos > max_pos)
    {
        return 0;
    }

    if (last_jump <= 0)
    {
        return 0;
    }

    int my_max = max(max(dragon(last_jump - 1, last_jump + cur_pos - 1), dragon(last_jump, last_jump + cur_pos)), dragon(last_jump + 1, last_jump + cur_pos + 1));

    dragon_arr[last_jump][cur_pos] = ps[cur_pos] + my_max;

    visited[last_jump][cur_pos] = true;

    // dragon_arr[last_jump][cur_pos] = my_max;
    // dragon_arr[last_jump][cur_pos] += ps[cur_pos];
    return dragon_arr[last_jump][cur_pos];
}

int main()
{
    // fastio

    int n;
    cin >> n;

    int j;
    cin >> j;

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        ps[p]++;

        if (p > max_pos)
        {
            max_pos = p;
        }
    }

    cout << dragon(j, j) << endl;

    return 0;
}