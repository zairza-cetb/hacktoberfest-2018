#include<bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    int adj[100][100],vis[100];
public:
    void read()
        {
            int i,j;

            cout<<"vertex"<<endl;
            cin>>v;
            for(i=0;i<v;i++)
            {
                for(j=0;j<v;j++)
                {
                    cin>>adj[i][j];
                    adj[j][i]=adj[i][j];
                }
            }
        }
    void bfs()
    {
        int q[v],i,f,r,u,source;
        cout<<"source"<<endl;
        cin>>source;
        f=r=0;
        q[r]=source;
        for(i=0;i<v;i++)
            vis[i]=0;
        while(f<=r)
        {
            u=q[f];
            f++;
            for(i=0;i<v;i++)
            {
                if(adj[u][i]==1&&vis[i]==0)
                    {
                        vis[i]=1;
                        r++;
                        q[r]=i;
                    }
            }
        }

    }
    void print()
    {
        for(int i=0;i<v;i++)
        {
            if(vis[i])
                cout<<"Vertex " <<i<<" is reachable"<<endl;
            else
                cout<<"Vertex " <<i<<" is not reachable"<<endl;
        }
    }
};
int main()
{
    graph g;
    g.read();
    g.bfs();
    g.print();
}
