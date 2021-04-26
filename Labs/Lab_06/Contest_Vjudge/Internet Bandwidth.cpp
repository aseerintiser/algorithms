#include<bits/stdc++.h>
using namespace std;

const int maxnodes = 100;
int pr[110],cap[110][110];

int s;
int t;
int n;

vector < vector < pair <int, int> > > g;

int bfs(int src,int des)
{
    int vis[110]= {0};
    vis[src]=1;
    pr[src]=-1;
    queue<int>Q;
    Q.push(src);

    while(!Q.empty())
    {
        int u=Q.front(); //front e jeta ase shei node ta nibo
        Q.pop(); //shekhan theke jei jei node visited na, shegulay jabo
        for(int i=1; i<=n; i++)
        {
            if(vis[i] or cap[u][i]<=0) continue;  //i node visited kina, ba u theke i edge ase kina
            Q.push(i);
            vis[i]=1;
            pr[i]=u;

        }
    }

    return vis[des] == 1;
}

int maxFlow(int src,int des)
{
    int f=0;
    while(bfs(src,des))
    {

        int path=1e9;
        for(int i=des; i!=src; i=pr[i]) path=min(path,cap[pr[i]][i]);

        for(int i=des; i!=src; i=pr[i])
        {

            int u=pr[i];
            int v=i;

            cap[u][v] -= path;
            cap[v][u] += path;

        }

        f+=path;

    }
    return f;
}


int main()
{

	int x;
	int y;
	int w;
	int CS;
	int flow;
	int k;
	int c;
	int p;

	scanf("%d", &CS);

	for (int cs = 1; cs <= CS; cs++) {
		scanf("%d", &n);
		scanf("%d", &s);
		scanf("%d", &t);
		scanf("%d", &c);

		memset(cap, 0, sizeof(cap));
		vector < vector < pair <int, int> > > tg(n+2);

		swap(tg, g);

		for (int i = 0; i < c; i++) {
			scanf("%d", &x);
			scanf("%d", &y);
			scanf("%d", &w);

			cap[x][y] += w;
			cap[y][x] += w;
			g[x].push_back(make_pair(y, w));
			g[y].push_back(make_pair(x, w));
		}

		printf("Case %d: %d\n", cs, maxFlow(s,t));
	}

}

