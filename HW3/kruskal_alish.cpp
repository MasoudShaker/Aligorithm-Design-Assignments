#include <bits/stdc++.h>

using namespace std;

const int max_n = 100005;
int n;

vector<pair<int, int>> graph[max_n];

int par[max_n];

priority_queue<pair<int, pair<int, int>>> pq;
vector<pair<int, pair<int, int>>> selected_edges;
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
    while (!pq.empty())
    {

        pair<int, pair<int, int>> edge = pq.top();
        pq.pop();

        int u, v;
        u = edge.second.first;
        v = edge.second.second;

        if (find(u) != find(v))
        {
            merge(u, v);
            selected_edges.push_back(edge);
        }

        if (selected_edges.size() == n - 1)
        {
            break;
        }
    }
}

int main()
{

    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        u--;
        v--;

        pair<int, pair<int, int>> edge = make_pair(w, make_pair(u, v));

        pq.push(edge);
    }

    kruskal();

    for (int i = 0; i < selected_edges.size(); i++)
    {
        cout << selected_edges[i].second.first << " " << selected_edges[i].second.second << endl;
    }
}