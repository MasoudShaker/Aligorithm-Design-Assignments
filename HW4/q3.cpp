#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define lli long long int

#define pb push_back

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000 + 20;

lli decorative_arr[10][max_n];

lli positions[10][max_n];

lli decorative_dp[max_n];

int first_num , second_num;

bool is_after;

lli longest_decorative;

int main()
{
    fastio

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            lli decorative_order;
            cin >> decorative_order;
            decorative_arr[i][j] = decorative_order;
            positions[i][decorative_arr[i][j]] = j;
        }
    }

    for (int j = 1; j <= n; j++){
        decorative_dp[j] = 1;
    }

    for (int m = 1; m<=n; m++){
        for (int p = 1; p <m; p++){
            first_num = decorative_arr[1][m];
            second_num = decorative_arr[1][p];

            is_after = true;

            for (int d = 2; d <= k; d++){
                if(is_after){
                    if(positions[d][first_num] <= positions[d][second_num]){
                        is_after = false;
                    }
                }
            }

            if (is_after){
                decorative_dp[first_num] = max(decorative_dp[first_num], decorative_dp[second_num] + 1);
            }
        }
    }

    for (int j = 1; j <=n; j++){
        longest_decorative = max(longest_decorative, decorative_dp[j]);
    }

    cout << longest_decorative <<endl;

            return 0;
        }