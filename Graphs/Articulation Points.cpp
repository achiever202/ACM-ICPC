/* Articulation point in an undirected connected graph is a point which when removed from the graph, leaves the graph disconnected.
 * All the articulation points can be found by using a O(V+E) algorithm using dfs.
 * For every node n, we calculate the lowest depth of a node that can be reached from all its neighbours and neighbours of all its descendents.
 * For the root node, it is an articulation point, if it has more than two children.
 * For other nodes, it is an articulation point if the lowest node reached by any of its child, is greater than equal to its depth. */
 
#include <iostream>
#include <stdio.h>
#include <vector>

#define ll long long int

using namespace std;

int nodes[3000][3000];
int pos_list[3000];
bool visited[3000];
int lowest[3000];
int depth[3000];
bool articulation_point[3000];
int parent[3000];
int children[3000];

void dfs(int node, int p, int d)
{
	visited[node] = true;
	depth[node] = d;
	parent[node] = p;

	lowest[node] = d;
	int current;

	for(int i=0; i<pos_list[node]; i++)
	{
		current = nodes[node][i];
		if(visited[current]==false)
		{
			children[node]++;
			dfs(current, node, d+1);

			if(lowest[current]<lowest[node])
				lowest[node] = lowest[current];

			if(p==-1 && children[node]>1)
				articulation_point[node] = true;

			if(p!=-1 && lowest[current]>=depth[node])
				articulation_point[node] = true;
		}
		else
		{
			if(p!=current && lowest[node]>depth[current])
				lowest[node] = depth[current];
		}
	}
}

int main()
{
	int t, n, m, k, a, b;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &m, &k);
		for(int i=0; i<n; i++)
		{
			pos_list[i] = 0;
			children[i] = 0;
			visited[i] = false;
			lowest[i] = -1;
			parent[i] = -1;
			articulation_point[i] = false;
			depth[i] = -1;
		}

		for(int i=0; i<m; i++)
		{
			scanf("%d %d", &a, &b);
			nodes[a][pos_list[a]] = b;
			pos_list[a]++;

			nodes[b][pos_list[b]] = a;
			pos_list[b]++;
		}

		dfs(0, -1, 0);

		int count = 0;
		for(int i=0; i<n; i++)
		{
			if(articulation_point[i]==true)
				count++;
		}

		printf("%d\n", count*k);
	}
	return 0;
}
