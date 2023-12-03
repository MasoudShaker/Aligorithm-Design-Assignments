#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> weights;

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;

        weights.push(w);
    }

    for (int i = 0; i < n; i++)
    {
        if (weights.empty())
        {
            cout << 0;
        }
        else if (weights.size() == 1)
        {
            cout << weights.top();
        }
        int x = weights.top();
        weights.pop();

        int y = weights.top();
        weights.pop();

        if (x != y)
        {
            int x_minus_y = x - y;
            weights.push(x_minus_y);
        }
    }
}
