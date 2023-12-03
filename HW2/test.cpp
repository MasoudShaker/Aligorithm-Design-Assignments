#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int max_n = 1000*100;

vector <int> graph[max_n];
	
bool visited[max_n];
int score[max_n];
int level[max_n];

int dfs(int start){
	visited[start]=true;
	int score_st = 1;

	if(graph[start].size()==1){
		score_st=1;
		score[start] = score_st;
		return score_st;
	}

	for(auto v: graph[start]){
		if(!visited[v]){
			score_st += dfs(v);
		}
	}

	score[start] = score_st;
	return score_st;

}

void bfs(int start){
	
	queue<int> Q;
	Q.push(start);

	while(!Q.empty()){
		int cur = Q.front();
		cout<<cur+1<<endl;
		Q.pop();
		visited[cur]=true;
		for(auto v: graph[cur]){
			if(!visited[v]){
				level[v] = level[cur]+1;
				Q.push(v);
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	

	int n;
	cin>>n;

	int m;
	cin>>m;

	for(int i=0; i<m; i++){
		int u; int v;
		cin>>u>>v;
		u --;
		v --;
		graph[u].push_back(v);
		graph[v].push_back(u);

	}


	// dfs(0);

	// for(int i = 0; i < n; i++){
	// 	cout<<score[i]<<" ";
	// }
	// cout<<endl;

}