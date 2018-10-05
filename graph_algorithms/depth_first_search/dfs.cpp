#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 10;
bool vis[N];
vector<int> graph[N];

void dfs(int a)
{
	vis[a] = true;
	for(int i : graph[a])
	{
		if(vis[i]) continue;
		dfs(i);
	}
}

int main()
{
	//input graph
	//call dfs(a) where a is starting vertex
	return 0;
}
