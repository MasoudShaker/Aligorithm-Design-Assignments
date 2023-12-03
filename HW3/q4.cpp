#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define mp make_pair
#define se selected_edges
#define pb push_back
#define F first
#define S second

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000000 + 20;

int n, par[max_n];

priority_queue<pair<int, pair<int, int>>> weight_and_vertices;

vector<pair<int, pair<int, int>>> se;

vector<int> graph_bfs[max_n];

bool visited[max_n];

void bfs(int start)
{

    queue<int> Q;
    Q.push(start);

    while (!Q.empty())
    {
        int current_node = Q.front();
        Q.pop();
        visited[current_node] = true;
        for (auto v : graph_bfs[current_node])
        {
            if (!visited[v])
            {
                visited[v] = true;
                Q.push(v);
            }
        }
    }
}

int find(int v)
{
    if (par[v] == v)
    {
        return v;
    }

    return par[v] = find(par[v]);
}

void merge(int u, int v)
{
    int leader1 = find(u);
    int leader2 = find(v);
    par[leader2] = leader1;
}

void kruskal()
{
    while (!weight_and_vertices.empty())
    {

        pair<int, pair<int, int>> edge = weight_and_vertices.top();
        weight_and_vertices.pop();

        int u, v;
        u = edge.S.F;
        v = edge.S.S;

        if (find(u) != find(v))
        {
            merge(u, v);
            se.pb(edge);
        }

        if (se.size() == n - 1)
        {
            break;
        }
    }
}

int main()
{
    fastio

    int max_sum;
    int e, c;
    int a, b, bridge_capacity;
    int no_answer = -1;

    cin >> n >> e >> c;

    if (n <= 0 || e <= 0)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        par[i] = i;
    }

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> bridge_capacity;

        pair<int, pair<int, int>> edge = mp(bridge_capacity, mp(a, b));

        weight_and_vertices.push(edge);

        graph_bfs[a].pb(b);
        graph_bfs[b].pb(a);
    }

    bfs(1);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cout << no_answer << endl;
            return 0;
        }
    }

    kruskal();

    for (int i = 0; i < se.size(); i++)
    {
        max_sum += se[i].F;
    }

    cout << max_sum << endl;
}