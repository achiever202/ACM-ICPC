#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

#define mod 1000000007
#define ll long long int
#define maxn 100004
#define seive_max 10000

using namespace std;

class tree
{
	public:
		double maximum;
		double minimum;

};

tree segment_tree[4*maxn];
double ar[maxn];

double max(double a, double b)
{
	if(a<b)
		return b;
	else
		return a;
}

double min(double a, double b)
{
	if(a<b)
		return a;
	else
		return b;
}

void init_segment_tree(ll node, ll start, ll end)
{
	if(start==end)
	{
		segment_tree[node].maximum = ar[start];
		segment_tree[node].minimum = ar[start];
	}

	else
	{
		ll mid = (start+end)/2;
		init_segment_tree(2*node, start, mid);
		init_segment_tree(2*node+1, mid+1, end);

		segment_tree[node].maximum = max(segment_tree[2*node].maximum, segment_tree[2*node+1].maximum);
		segment_tree[node].minimum = min(segment_tree[2*node].minimum, segment_tree[2*node+1].minimum);
	}

	//cout<<node<<" "<<start<<" "<<end<<" "<<segment_tree[node].minimum<<" "<<segment_tree[node].maximum<<endl;
}

ll query_min(ll node, ll start, ll end, ll x, ll y)
{
	if(x>end || y<start)
		return -1;

	else if(start>=x && end<=y)
		return segment_tree[node].minimum;

	else
	{
		ll mid = (start+end)/2;
		double left = query_min(2*node, start, mid, x, y);
		double right = query_min(2*node+1, mid+1, end, x, y);

		if(left==-1)
			return right;
		if(right==-1)
			return left;
		return min(left, right);
	}
}

ll query_max(ll node, ll start, ll end, ll x, ll y)
{
	if(x>end || y<start)
		return -1;

	else if(start>=x && end<=y)
		return segment_tree[node].maximum;

	else
	{
		ll mid = (start+end)/2;
		double left = query_max(2*node, start, mid, x, y);
		double right = query_max(2*node+1, mid+1, end, x, y);

		if(left==-1)
			return right;
		if(right==-1)
			return left;
		return max(left, right);
	}
}

int main()
{
	ll n;
	cin>>n;

	for(ll i=1; i<=n; i++)
		cin>>ar[i];

	init_segment_tree(1, 1, n);

	ll q, x, y;
	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		x++, y++;
		
		double ans;

		double max_between = query_max(1, 1, n, x, y);
		double min_between = query_min(1, 1, n, x, y);
		ans = min_between;

		if(x>1 && y<n)
		{
			double max_left = query_max(1, 1, n, 1, x-1);
			double max_right = query_max(1, 1, n, y+1, n);
			double temp = (max_between-min_between)/2;
			ans += max(temp, max(max_left, max_right));
		}

		else if(x==1 && y==n)
		{
			ans += (max_between - min_between)/2;
		}

		else if(x==1)
		{
			double max_right = query_max(1, 1, n, y+1, n);

			ans += max(((max_between-min_between)/2), max_right);
		}

		else
		{
			double max_left = query_max(1, 1, n, 1, x-1);

			ans += max(((max_between-min_between)/2), max_left);
		}
		printf("%0.1lf\n", ans);

	}

	return 0;
}

