/* This program calculates the minimum spanning tree on a undirected connected graph, with positive weights.
 * It returns the cost of the minimum spanning tree.
 * It uses prim's algorithm, using a proprity queue.
 */

#include <iostream>
#include <vector>

#define ll long long int

using namespace std;

class graph
{
	public:
		ll node;
		ll weight;

		graph(ll i, ll j)
		{
			node = i;
			weight = j;
		}

		graph(ll i)
		{
			node = i;
		}
};


class spanning_tree
{
	public:
		// current stores the current node.
		// parent stores the node from which it is reached.
		// child stores the child nodes.
		// cost stores the cost to reach this node.
		ll current;
		ll parent;
		ll child;
		ll cost;

		// parameterised constructor
		spanning_tree(ll i, ll j, ll k, ll l)
		{
			current = i;
			parent = j;
			child = k;
			cost = l;
		}

		// default constructor
		spanning_tree()
		{

		}
};

/* This function performs the feapify down operation on the priority queue. */
void heapify_down(spanning_tree ar[], ll *n, ll i, ll pos[])
{
	// the left child.
	ll j = 2*i;

	// if left child exists.
	if(j<=*n)
	{
		// if right child exists.
		if(j+1<=*n)
		{
			// the child with smaller cost.
			if(ar[j+1].cost<ar[j].cost && ar[j+1].cost!=-1)
				j = j+1;
		}

		// swap if the cost of child is smaller.
		if(ar[i].cost>ar[j].cost && ar[j].cost!=-1)
		{
			spanning_tree temp;
			temp = ar[i];
			ar[i] = ar[j];
			ar[j] = temp;

			ll temp_pos = pos[ar[i].current];
			pos[ar[i].current] = pos[ar[j].current];
			pos[ar[j].current] = temp_pos;

			heapify_down(ar, n, j, pos);
		}
	}
}

// extracting the minimum from the priority queue.
void extract_min(spanning_tree ar[], ll *n, ll pos[])
{
	// setting the pos of the miniumum to be -1, so that it is removed.
	pos[ar[1].current] = -1;

	// swapping the last element with the first one.
	ar[1] = ar[(*n)];

	// setting its pos to be 1.
	pos[ar[1].current] = 1;

	*n = (*n)-1;

	// heapifying down.
	heapify_down(ar, n, 1, pos);
}

/* This function performs the heapify operation on priority queue */
void heapify(spanning_tree ar[], ll n, ll pos[], ll i)
{
	// if it has a parent.
	if(i>1)
	{
		// j is the parent.
		ll j = i/2;

		// if the cost of parent is greater or -1, swap.
		if(ar[i].cost<ar[j].cost || ar[j].cost==-1)
		{
			spanning_tree temp;
			temp = ar[i];
			ar[i] = ar[j];
			ar[j] = temp;

			ll temp_pos;
			temp_pos = pos[ar[i].current];
			pos[ar[i].current] = pos[ar[j].current];
			pos[ar[j].current] = temp_pos;

			heapify(ar, n, pos, j);
		}
	}
}

/* This function calculates the smallest cost and builds the minimum spanning tree. */
ll minimum_spanning_tree(vector <graph> buildings[], ll n)
{
	// Creating a heap.
	spanning_tree ar[n+1];

	// creating a pos array, that stores the position of a node in the priority queue.
	ll pos[n+1];

	// inititalising the defaults.
	for(ll i=0; i<=n; i++)
	{
		ar[i].current = i;
		ar[i].parent = -1;
		ar[i].child = -1;
		ar[i].cost = -1;
		pos[i] = i;
	}

	ar[1].cost = 0;

	ll total_cost = 0;
	ll current_nodes = n;

	// while there are nodes in the queue.
	while(current_nodes>0)
	{
		/*for(ll i=1; i<=n; i++)
			cout<<ar[i].current<<" "<<ar[i].parent<<" "<<ar[i].cost<<endl;
		cout<<endl;*/

		// extracting the minimum and adding its cost.
		ll min_node = ar[1].current;
		total_cost += ar[1].cost;

		extract_min(ar, &current_nodes, pos);

		// updating the cost of all its neighbours.
		for(ll i=0; i<buildings[min_node].size(); i++)
		{
			ll temp_pos = pos[buildings[min_node][i].node];
			if(temp_pos!=-1)
			{
				if(ar[temp_pos].cost>buildings[min_node][i].weight || ar[temp_pos].cost==-1)
				{
					ar[temp_pos].cost = buildings[min_node][i].weight;
					ar[temp_pos].parent = min_node;
					heapify(ar, current_nodes, pos, temp_pos);
				}
			}
		}

	}

	return total_cost;
}

int main()
{
	ll n, m, a, b, c;

	// n are the number of nodes, m is the number of edges.
	cin>>n>>m;

	// storing the graph as adjacency list.
	vector <graph> nodes[n+1];

	for(ll i=0; i<m; i++)
	{
		// edge between a and b with weight c.
		cin>>a>>b>>c;
		nodes[a].push_back(graph(b, c));
		nodes[b].push_back(graph(a, c));
	}

	ll cost = minimum_spanning_tree(nodes, n);
	cout<<cost<<endl;
}
