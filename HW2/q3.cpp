#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define Pair pair<int, int>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int max_n = 1000 + 5;
char rectangle[max_n][max_n];
int n, m;
int num_of_points = 0;
bool visited[max_n][max_n];

void bfs(int i, int j)
{
    queue<Pair> Q;
    Pair node(i, j);

    int x, y;
    Q.push(node);
    visited[n][m] = true;

    while (!Q.empty())
    {
        node = Q.front();
        Q.pop();
        int row = node.first;
        int col = node.second;
        
        if (!(col == m-1))
        {
            if (!(row == n-1) && !visited[row+1][col])
            {
                if (rectangle[row+1][col] == '-')
                {
                    Q.push(Pair(row+1, col));
                    visited[row+1][col] = true;
                    num_of_points++;
                }
            }
            if (!(row == 0) && !visited[row-1][col])
            {
                if (rectangle[row-1][col] == '-')
                {
                    Q.push(Pair(row-1, col));
                    visited[row-1][col] = true;
                    num_of_points++;
                }
            }
        }
        if (!(col == m-1) && !visited[row][col+1])
        {
            if (rectangle[row][col+1] == '-' && !(col+1 == m-1))
            {
                Q.push(Pair(row, col+1));
                visited[row][col+1] = true;
                num_of_points++;
            }
        }
        if (!(col == 0) && !visited[row][col-1])
        {
            if (rectangle[row][col-1] == '-' && !(col-1 == m-1))
            {
                Q.push(Pair(row, col-1));
                visited[row][col-1] = true;
                num_of_points++;
            }
        }
    }
}
int main()
{
    fastio
    
    n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> rectangle[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (visited[i][j])
            {
                visited[i][j] = false;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (rectangle[i][m-1] == '-')
        {
            bfs(i, m-1);
        }
    }
    cout << num_of_points;
}