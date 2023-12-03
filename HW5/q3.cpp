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

#include <bits/stdc++.h>

using namespace std;

string ans;

bool alish_equal(string a, string b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    else if (a.size() % 2 != 0)
    {
        if (a == b){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        bool first_constraint = alish_equal(a.substr(0, a.size() / 2), b.substr(0, b.size() / 2)) && alish_equal(a.substr(a.size() / 2, a.size()), b.substr(b.size() / 2, b.size()));
        bool second_constraint = alish_equal(a.substr(0, a.size() / 2), b.substr(b.size() / 2, b.size())) && alish_equal(a.substr(a.size() / 2, a.size()), b.substr(0, b.size() / 2));

        return first_constraint || second_constraint;
    }
}

int main()
{
    fastio

    string a, b;

    cin >> a >> b;

    if (alish_equal(a, b))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}