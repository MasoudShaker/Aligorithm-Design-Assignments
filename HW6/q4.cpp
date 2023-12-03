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

const int max_n = 20;
int charomatic_num = max_n;
int color[max_n];
vector<int> adj_color[max_n];

int num_of_colors(int num_of_vertices)
{
    set<int> different_colors;

    foreq(i, 1, num_of_vertices)
    {
        if (color[i] != -176)
        {
            different_colors.ins(color[i]);
        }
    }
    return different_colors.size();
}

int coloring(int num_of_vertices, int vertex)
{
    if (vertex == num_of_vertices + 1)
    {
        charomatic_num = min(num_of_colors(num_of_vertices), charomatic_num);

        return 0;
    }

    if (num_of_colors(num_of_vertices) < charomatic_num)
    {
        bool reserved_colors[max_n] = {};

        for (int cl : adj_color[vertex])
        {
            if (color[cl] != -176)
            {
                reserved_colors[color[cl]] = true;
            }
        }

        foreq(i, 1, num_of_vertices)
        {
            if (reserved_colors[i] == false)
            {
                color[vertex] = i;
                coloring(num_of_vertices, vertex + 1);
            }
        }

        color[vertex] = -176;
    }

    return charomatic_num;
}

int main()
{
    int n, m;
    cin >> n >> m;

    if (m <= 0)
    {
        cout << 1 << endl;
        return 0;
    }

    else if (n <= 1)
    {
        cout << 1 << endl;
        return 0;
    }

    else
    {
        forl(i, 0, m)
        {
            int u, v;
            cin >> u >> v;

            adj_color[u].pb(v);
            adj_color[v].pb(u);
        }

        foreq(i, 1, max_n)
        {
            color[i] = -176;
        }

        color[1] = 1;

        cout << coloring(n, 2) << endl;
    }
}
