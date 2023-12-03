#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int max_n = 100000 + 5;
int value[max_n];
int first_value;
ll int max_sum_of_values[max_n];

int main()
{
    int n;
    cin >> n;

    max_sum_of_values[0] = 0;

    cin >> first_value;
    max_sum_of_values[1] = first_value;

    for (int i = 2; i <= n; i++)
    {
        cin >> value[i];

        max_sum_of_values[i] = max(max_sum_of_values[i - 1], max_sum_of_values[i - 2] + value[i]);   
    }

    cout << max_sum_of_values[n] << endl;

    vector<int> tableau;

    while (n > 0)
    {
        if (n == 1)
        {
            tableau.push_back(n);
            n--;
        }

        else
        {
            if (max_sum_of_values[n] == max_sum_of_values[n - 2] + value[n])
            {
                tableau.push_back(n);
                n -= 2;
            }

            else
            {
                n--;
            }
        }
    }

    cout << tableau.size() << endl;

    for (int j = tableau.size() - 1; j >= 0; j--)
    {
        cout << tableau[j];

        if (j > 0){
            cout << ' ';
        }
    }
}
