#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

#define max_nodes_size 100005
#define ll long long int
#define mod 1000000007
using namespace std;

class edge
{
	public:
		ll node;
		ll cost;

	edge(ll i, ll j)
	{
		node = i;
		cost = j;
	}
};

class graph
{
	public:
		ll node;
		vector <edge> edges;
		ll parent;
		ll cost;
		ll level;
}nodes[max_nodes_size];

ll nodes_size;
ll edge_size;
ll visited[max_nodes_size];

/* comparator functions. */
bool comp_edge_node(edge i, edge j)
{
	return i.node<j.node;
}

bool comp_edge_cost(edge i, edge j)
{
	return i.cost<j.cost;
}

/* fill array with a value. */
void fill_array(ll ar[], ll value, ll size)
{
	for(ll i=0; i<size; i++)
		ar[i] = value;
}

void input_graph(bool is_undirected, bool is_cost, bool is_tree)
{
	cin>>nodes_size;

	for(ll i=1; i<=nodes_size; i++)
	{
		nodes[i].node = i;
		nodes[i].parent = -1;
		nodes[i].cost = -1;
		nodes[i].edges.clear();
	}

	if(is_tree)
		edge_size = nodes_size-1;
	else
		cin>>edge_size;

	for(ll i=0; i<edge_size; i++)
	{
		ll a, b, c;
		cin>>a>>b;
		if(is_cost)
		{
			cin>>c;
			nodes[a].edges.push_back(edge(b, c));
			if(is_undirected)
				nodes[b].edges.push_back(edge(a, c));
		}
		else
		{
			nodes[a].edges.push_back(edge(b, 1));
			if(is_undirected)
				nodes[b].edges.push_back(edge(a, 1));
		}
	}
}

ll search_index(ll node, ll dest, ll start, ll end)
{
	if(end-start<=1)
	{
		if(nodes[node].edges[start].node==dest)
			return start;

		if(nodes[node].edges[end].node==dest)
			return end;

		return -1;
	}

	ll mid = (start+end)/2;

	if(nodes[node].edges[mid].node>=dest)
		return search_index(node, dest, start, mid);

	return search_index(node, dest, mid+1, end);
}

void recursive_dfs(ll node, ll parent)
{
	visited[node] = 1;

	for(ll i=0; i<nodes[node].edges.size(); i++)
	{
		if(nodes[node].edges[i].node!=parent)
		{
			if(!visited[nodes[node].edges[i].node])
			{
				recursive_dfs(nodes[node].edges[i].node, node);
			}
		}
	}
}

void iterative_dfs(ll node)
{
	stack <ll> dfs;
	nodes[node].parent = -1;
	nodes[node].level = 0;
	visited[node] = 1;
	dfs.push(node);

	while(!dfs.empty())
	{
		ll cur_node = dfs.top();
		dfs.pop();

		for(ll i=0; i<nodes[cur_node].edges.size(); i++)
		{
			if(nodes[cur_node].edges[i].node!=nodes[cur_node].parent)
			{
				ll next_node = nodes[cur_node].edges[i].node;
				if(!visited[next_node])
				{
					visited[next_node] = 1;
					nodes[next_node].level = nodes[cur_node].level+1;
					nodes[next_node].parent = cur_node;
					dfs.push(next_node);
				}
			}
		}
	}
}
