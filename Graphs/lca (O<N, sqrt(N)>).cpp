/*
 * Author: Adarsh Pugalia
 * This program finds the lowest comman ancestor.
 * Preprocessing: O(N)
 * Query: O(sqrt(H)) = O(sqrt(N))
 *
 * Assumption: The nodes are assumed to be 1 indexed.
 * The levels are divided in blocks similar to RMQ.
 * p[] stores the least ancestor of the node in the next upper block.
 * For the topmost section, p[] = 1.
 *
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

/* root stores the sqrt of the node size. */
ll p[max_nodes_size], root;

/* 
 * This routine preprocess the p[] array for finding lcm.
 * @param node: the root of the tree.
 */
void iterative_dfs(ll node)
{
	stack <ll> dfs;
	nodes[node].parent = -1;
	visited[node] = 1;
	nodes[node].level = 0;
	dfs.push(node);

	while(!dfs.empty())
	{
		ll cur_node = dfs.top();
		dfs.pop();

		/* 
		 * if the node is in the topmost section, p[] = 1.
		 * if the nodes is in the first level of a block, p[] = parent of the node.
		 * else p[] = p[parent of the node]
		 */
		if(nodes[cur_node].level<root)
			p[cur_node] = 1;
		else
		{
			if(nodes[cur_node].level%root==0)
				p[cur_node] = nodes[cur_node].parent;
			else
				p[cur_node] = p[nodes[cur_node].parent];
		}

		for(ll i=0; i<nodes[cur_node].edges.size(); i++)
		{
			if(nodes[cur_node].edges[i].node!=nodes[cur_node].parent)
			{
				if(!visited[nodes[cur_node].edges[i].node])
				{
					visited[nodes[cur_node].edges[i].node] = 1;
					nodes[nodes[cur_node].edges[i].node].parent = cur_node;
					nodes[nodes[cur_node].edges[i].node].level = nodes[cur_node].level+1;
					dfs.push(nodes[cur_node].edges[i].node);
				}
			}
		}
	}
}

/* This function returns the lca of nodes x and y. */
ll lca(ll x, ll y)
{
	/* Untill the nodes are in same section. */
	while(p[x]!=p[y])
	{
		if(nodes[x].level>nodes[y].level)
			x = p[x];
		else
			y = p[y];
	}

	/* nodes are in the same block, iterating over the parents to reach lca. */
	while(x!=y)
	{
		if(nodes[x].level>nodes[y].level)
			x = nodes[x].parent;
		else
			y = nodes[y].parent;
	}

	return x;
}

int main()
{
	input_graph(true, false, true);

	/* finding the size of the block. */
	root = pow(nodes_size, 0.5);

	fill_array(visited, 0, nodes_size);

	/* assuming 1 is the root, call this function with the root of the tree. */
	iterative_dfs(1);
	
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
