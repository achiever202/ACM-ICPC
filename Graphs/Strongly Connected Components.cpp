#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <string.h>
#include <stack>

#define max_nodes_size 100005
#define ll long long int
using namespace std;

ll nodes_size;
ll edge_size;

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
		vector <edge> edges;
		ll parent;
		ll cost;
		vector <ll> children;
}nodes[max_nodes_size], reversed_nodes[max_nodes_size];

ll visited[max_nodes_size];
vector <ll> strongly_connected_components[max_nodes_size];
vector <ll> strongly_dfs_order;
ll num_strongly_connected_components;

void fill_array(ll ar[], ll value, ll size)
{
	for(ll i=0; i<size; i++)
		ar[i] = value;
}

void print_ll_vector(vector <ll> v)
{
	for(ll i=0; i<v.size(); i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

void reverse_graph()
{
	for(ll i=0; i<nodes_size; i++)
	{
		for(ll j=0; j<nodes[i].edges.size(); j++)
			reversed_nodes[nodes[i].edges[j].node].edges.push_back(edge(i, nodes[i].edges[j].cost));
	}
}

void input_graph(bool is_undirected, bool is_cost, bool is_tree)
{
	cin>>nodes_size;

	for(ll i=0; i<=nodes_size; i++)
	{
		nodes[i].edges.clear();
		reversed_nodes[i].edges.clear();
		nodes[i].parent = reversed_nodes[i].parent = -1;
		nodes[i].cost = reversed_nodes[i].cost = -1;
		nodes[i].children.clear(); reversed_nodes[i].children.clear();
	}

	if(is_tree)
		edge_size = nodes_size-1;
	else
		cin>>edge_size;

	for(ll i=0; i<edge_size; i++)
	{
		ll a, b, c;
		cin>>a>>b;
		a--; b--;
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

void strongly_dfs_second(ll node)
{
	stack <ll> dfs_stack;
	dfs_stack.push(node);
	visited[node] = 1;
	while(!dfs_stack.empty())
	{
		ll cur_node = dfs_stack.top();
		dfs_stack.pop();
		strongly_connected_components[num_strongly_connected_components].push_back(cur_node);
		for(ll i=0; i<reversed_nodes[cur_node].edges.size(); i++)
		{
			if(!visited[reversed_nodes[cur_node].edges[i].node])
			{
				visited[reversed_nodes[cur_node].edges[i].node] = 1;
				dfs_stack.push(reversed_nodes[cur_node].edges[i].node);
			}
		}
	}
}

void strongly_dfs_first(ll node)
{
	visited[node] = 1;
	for(ll i=0; i<nodes[node].edges.size(); i++)
	{
		if(!visited[nodes[node].edges[i].node])
			strongly_dfs_first(nodes[node].edges[i].node);
	}

	strongly_dfs_order.push_back(node);
}

void calc_strongly_connected_components()
{
	for(ll i=0; i<max_nodes_size; i++)
		strongly_connected_components[i].clear();

	num_strongly_connected_components = 0;
	fill_array(visited, 0, nodes_size);
	for(ll i=0; i<nodes_size; i++)
		if(!visited[i])
			strongly_dfs_first(i);


	reverse_graph();
	fill_array(visited, 0, nodes_size);

	for(ll i=strongly_dfs_order.size()-1; i>=0; i--)
	{
		if(!visited[strongly_dfs_order[i]])
		{
			strongly_dfs_second(strongly_dfs_order[i]);
			num_strongly_connected_components++;
		}
	}
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		input_graph(false, false, false);
		calc_strongly_connected_components();
	}
	return 0;
}
