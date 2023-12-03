#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back

#include <bits/stdc++.h>

using namespace std;

const int max_n = 10000 + 20;

int par[max_n];

int size_of_set[max_n];

vector<int> sizes;

int min_num;

int limit = 500;

int find(int v)
{
    if (par[v] == v)
    {
        return v;
    }

    return par[v] = find(par[v]);
}

void make_set(int v)
{
    par[v] = v;
    size_of_set[v] = 1;
}

void merge(int v, int u)
{
    int p_v = find(v);
    int p_u = find(u);

    if (p_v != p_u)
    {
        // if (size_of_set[v] < size_of_set[u])
        // {
        //     swap(v, u);
        // }
        par[p_u] = par[p_v];

        // cout << size_of_set[v] << endl;
        // cout << size_of_set[u] << endl;

        // int p_u = par[u];
        // int p_v = par[v];

        sizes.pb(2 * size_of_set[p_u] * size_of_set[p_v]);
        size_of_set[p_v] += size_of_set[p_u];
    }
}

int main()
{
    fastio

    int n;
    cin >> n;

    int arr1[max_n], arr2[max_n];
    int a1, a2;

    for (int i = 0; i < limit; i++)
    {
        make_set(i);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a1;
        arr1[i] = a1;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a2;
        arr2[i] = a2;
    }

    for (int i = 0; i < n; i++)
    {
        make_set(arr1[i]);
        make_set(arr2[i]);
    }

    for (int i = 0; i < n; i++)
    {

        if (find(arr1[i]) != find(arr2[i]))
        {
            merge(arr1[i], arr2[i]);
            min_num++;
        }
    }

    cout << min_num << endl;

    for (int i = 0; i < sizes.size(); i++)
    {
        cout << sizes[i] << endl;
    }

    // for (int i = 1; i <= n; i++)
    // {

    //     cout << size_of_set[i] << endl;
    // }

    return 0;
}