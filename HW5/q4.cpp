#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define forl(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define foreq(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ins insert
#define bg begin
#define er erase

#include <bits/stdc++.h>

using namespace std;
typedef pair<ll, ll> ll_pair;

const ll max_n = 100000 + 20;
const ll inf = 1e15;

vector<ll_pair> neighbour[max_n];
set<ll_pair> dig_set;
ll min_dist[max_n];
ll final_ans;
ll k, n;

int main()
{
    ll m;
    cin >> n >> m >> k;

    foreq(i, 1, m)
    {
        ll u, v, w;
        cin >> u >> v >> w;

        u--;
        v--;

        neighbour[u].pb(mp(v, w));
        neighbour[v].pb(mp(u, w));
    }

    int source = 0;

    forl (i, 0, n){
        min_dist[i] = inf;
    }

    min_dist[source] = 0;

    forl (i, 0, n){
        dig_set.insert({min_dist[i], i});
    }

    forl(i, 0, k)
    {
        ll vertex_u = dig_set.bg()->S;
        dig_set.erase(dig_set.bg());

        for (ll_pair edge : neighbour[vertex_u])
        {
            ll vertex_v = edge.F;
            ll weight = edge.S;

            if (min_dist[vertex_u] + weight < min_dist[vertex_v])
            {
                dig_set.er({min_dist[vertex_v], vertex_v});
                min_dist[vertex_v] = min_dist[vertex_u] + weight;
                dig_set.ins({min_dist[vertex_v], vertex_v});
            }
        }

        if (i == k - 1)
        {
            if (min_dist[vertex_u] == inf)
            {
                final_ans = -1;
            }
            else{
                final_ans = min_dist[vertex_u];
            }
        }
    }

    cout << final_ans << endl;

    return 0;
}