#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
bool vis[N];
vector<int> graph[N];


void bfs(int a)
{
	queue<int> q;
	q.push(a);
	vis[a] = true;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(int i : graph[x])
		{
			if(!vis[i)
			{
				vis[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	//insert graph
	//run bfs(a) where a is starting vertex
	return 0;
}
