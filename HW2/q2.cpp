#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int max_n = 2000;

vector<int> graph[max_n];

int dist_bfs(int start)
{
    bool visited[max_n] = {false};
    int level[max_n] = {0};
    int num_of_vertices = 0;

    queue<int> Q;
    Q.push(start);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        visited[cur] = true;
        for (auto v : graph[cur])
        {
            if (!visited[v])
            {
                visited[v] = true;
                level[v] = level[cur] + 1;
                num_of_vertices += level[v];
                Q.push(v);
            }
        }
    }
    return num_of_vertices;
}

int main()
{
    fastio
    
    int n , m;
    cin >> n >> m;

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int minimum = dist_bfs(1);
    int min_index = 1;

    for (int i = 2; i < n; i++)
    {
        if (dist_bfs(i) < minimum)
        {
            minimum = dist_bfs(i);
            min_index = i;
        }
    }
    cout << min_index;
    return 0;
}
