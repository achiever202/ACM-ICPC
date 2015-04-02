/*
 * Author: Adarsh Pugalia
 * This program finds the lowest comman ancestor.
 * Preprocessing: O(NlogN)
 * Query: O(log(H)) = O(log(N))
 *
 * Assumption: The nodes are assumed to be 1 indexed.
 * p[i][j] stores the least ancestor of the 2^jth ancestor of ith node.
 */

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
#define max_log_size 17
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
	for(ll i=0; i<=size; i++)
		ar[i] = value;
}

void input_graph(bool is_undirected, bool is_cost, bool is_tree)
{
	cin>>nodes_size;

	for(ll i=1; i<=nodes_size; i++)
	{
		nodes[i].node = i;
		nodes[i].edges.clear();
		nodes[i].parent = -1;
		nodes[i].cost = -1;
		nodes[i].level = 0;
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

ll p[max_nodes_size][max_log_size], root;

/* 
 * This routine preprocess the p[][] array for finding lcm.
 * @param node: the root of the tree.
 */
void preprocess()
{
	/* initializing each p[][] with -1. */
	for(ll i=1; i<=nodes_size; i++)
		for(ll j=0; 1<<j<=nodes_size; j++)
			p[i][j] = -1;

	/* initializing the parent for each node. */
	for(ll i=1; i<=nodes_size; i++)
		p[i][0] = nodes[i].parent;

	/* bottom up dp. */
	for(ll j=1; 1<<j<=nodes_size; j++)
	{
		for(ll i=1; i<=nodes_size; i++)
		{
			if(p[i][j-1]!=-1)
				p[i][j] = p[p[i][j-1]][j-1];
		}
	}
}


/* This function returns the lca of nodes x and y. */
ll lca(ll x, ll y)
{
	ll node_log;

	/* swap if level of x if smaller than level of y. */
	if(nodes[x].level<nodes[y].level)
	{
		ll temp = x;
		x = y;
		y = temp;
	}

	/* computing the value of log(x). */
	for(node_log=1; 1<<node_log<=nodes[x].level; node_log++);
	node_log--;

	/* finding the ancestor of x at the same level as y. */
	for(ll i=node_log; i>=0; i--)
	{
		if(nodes[x].level - (1<<i) >= nodes[y].level)
		{
			x = p[x][i];
		}
	}

	if(x==y)
		return x;

	/* computing lca using p[][]. */
	for(ll i=node_log; i>=0; i--)
	{
		if(p[x][i]!=-1 && p[x][i]!=p[y][i])
		{
			x = p[x][i];
			y = p[y][i];
		}
	}

	return nodes[x].parent;
}

int main()
{
	input_graph(true, false, true);

	/* finding the size of the block. */
	root = pow(nodes_size, 0.5);

	fill_array(visited, 0, nodes_size);

	preprocess();
	
	ll q;
	cin>>q;
	while(q--)
	{
		ll a, b;
		cin>>a>>b;
		cout<<lca(a, b)<<endl;
	}

	return 0;
}
