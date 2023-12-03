#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#include <iostream>
#include <set>
#include <iterator>
#include <stack>

using namespace std;

int n, max_path_distance, third_node;
set<int> path;
int *dis_from_path;
bool *checked;

void reset_checked(){
    for (int i = 0; i < n; ++i){
        checked[i] = false;
    }
}

int max_node(set<int> *edges, int node , int passed_distance){
    static int max_distance = 0;
    static int maximum_node = 0;
    
    if (checked[node-1]){
        return maximum_node;
    }

    checked[node-1] = true;
    
    set<int>::iterator itr;
    for (itr = edges[node-1].begin(); itr != edges[node-1].end(); ++itr){
        int t = *itr;
        int dis;

        if (!checked[t-1]){
            dis = max_node(edges, t, passed_distance + 1);
        } 
        else if (edges[node-1].size() == 1 && passed_distance > max_distance){
            max_distance = passed_distance;
            maximum_node = node;
        }
    }
    return maximum_node;
}

bool find_path(set<int> *edges, int node, int goal){
    checked[node-1] = true;

    if (node == goal){
        return true;
    }

    set<int>::iterator itr;
    for (itr = edges[node-1].begin(); itr != edges[node-1].end(); ++itr){
        int t = *itr;
        if (!checked[t-1]){
            bool b = find_path(edges, t, goal);
            if (b){
                path.insert(t);
                return true;
            }
        }
    }
    return false;
}

void find_third_node(set<int> *edges, int node, int dis){
    checked[node-1] = true;
    if (!path.count(node)){
        dis++;
        if (dis > max_path_distance){
            max_path_distance = dis;
            third_node = node;
        }
    }

    set<int>::iterator itr;
    for (itr = edges[node-1].begin(); itr != edges[node-1].end(); ++itr){
        int t = *itr;
        if (!checked[t-1]){
            find_third_node(edges, t, dis);
        }
    }
}

int main(){

    fastio

    max_path_distance = 0;
    third_node = 0;
    cin >> n;

    set<int> *edges = new set<int>[n];

    for (int i = 0; i < n - 1; ++i){
        int t1, t2;
        cin >> t1 >> t2;
        edges[t1-1].insert(t2);
        edges[t2-1].insert(t1);
    }

    checked = new bool[n]();
    int n1 = max_node(edges, 1, 0);

    reset_checked();
    int n2 = max_node(edges, n1, 0);

    if (n1 == n2){
        n1 = 1;
    }

    path.insert(n1);

    reset_checked();
    find_path(edges, n1, n2);

    reset_checked();
    find_third_node(edges, n1, 0);

    if (third_node == 0){
        third_node = 2;
    }

    cout << (path.size() + max_path_distance) - 1 << endl;
    cout << n1 << endl;
    cout << n2 << endl;
    cout << third_node;
    return 0;
}