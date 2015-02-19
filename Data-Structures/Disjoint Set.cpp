#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

#define max_nodes_size 100005
#define max_size 105
#define ll long long int
#define mod 1000000007
using namespace std;

ll disjoint_set[max_size], rank[max_size];

void create_set(ll n)
{
	for(ll i=1; i<=n; i++)
	{
		disjoint_set[i] = i;
		rank[i] = 1;
	}
}

ll find_parent(ll index)
{
	ll temp = index;
	while(disjoint_set[index]!=index)
	{
		disjoint_set[index] = disjoint_set[disjoint_set[index]];
		index = disjoint_set[index];
	}
	
	disjoint_set[temp] = index;
	return index;
}

ll merge_sets(ll i, ll j)
{
	ll parent1 = find_parent(i);
	ll parent2 = find_parent(j);

	if(parent1!=parent2)
	{
		if(rank[parent1]>rank[parent2])
		{
			rank[parent1] += rank[parent2];
			rank[parent2] = 0;

			disjoint_set[parent2] = parent1;
		}
		else
		{
			rank[parent2] += rank[parent1];
			rank[parent1] = 0;

			disjoint_set[parent1] = parent2;	
		}
	}
}
