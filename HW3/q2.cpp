#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000000 + 20;
int num_of_teams = 1;
int sad[max_n];
int size_of_sad;
int n;
int a;
int max_a;
int counter;

int main()
{
    fastio

    cin >> n;

    if (n <= 1)
    {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sad[i] = a;
    }

    sort(sad, sad + n);
    max_a = sad[n - 1];
    size_of_sad = n - max_a;

    for (int i = 0; i < size_of_sad; i++)
    {
        counter++;
        if (counter == sad[i])
        {
            num_of_teams++;
            counter = 0;
        }
    } 

    cout << num_of_teams << endl;
    return 0;
}