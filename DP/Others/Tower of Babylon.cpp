/*
 * Here, what we do is we create all the three orientations of a brick and push it on a vector.
 * Then we sort the vector first on the basis of x, and then on the basis of y, i.e the base of the brick.
 * Next we do a backward dp, where we try to put a smaller brick on a largre brick moving back.
 * At, the end we look for the largest among those.
 *
 * Thus, the state dp[i] implies the maximum height with the base as the ith brick in the vector.
 */
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>

#define mod 1000000009
#define ll long long int
#define maxn 5005
#define seive_max 35000

#define pb push_back
#define fact_max 5005

using namespace std;

class brick
{
	public:
		ll x;
		ll y;
		ll z;

		brick()
		{

		}

		brick(ll i, ll j, ll k)
		{
			x = i;
			y = j;
			z = k;
		}
};

bool comp(brick i, brick j)
{
	if(i.x==j.x)
		return i.y>j.y;

	return i.x>j.x;
}

brick ar[50];

int main()
{
	ll n, a, b, c;
	cin>>n;
	while(n)
	{
		for(ll i=0; i<n; i++)
		{
			cin>>a>>b>>c;

			if(a>b && a>c)
			{
				ar[i].x = a;
				if(b>c)
				{
					ar[i].y = b;
					ar[i].z = c;
				}
				else
				{
					ar[i].y = c;
					ar[i].z = b;
				}

				continue;
			}

			if(b>=a && b>=c)
			{
				ar[i].x = b;
				if(a>c)
				{
					ar[i].y = a;
					ar[i].z = c;
				}
				else
				{
					ar[i].y = c;
					ar[i].z = a;
				}
				continue;
			}

			ar[i].x = c;
			if(a>b)
			{
				ar[i].y = a;
				ar[i].z = b;
			}
			else
			{
				ar[i].y = b;
				ar[i].z = a;
			}
		}

		vector <brick> bricks;
		for(ll i=0; i<n; i++)
		{
			bricks.pb(brick(ar[i].x, ar[i].y, ar[i].z));
			bricks.pb(brick(ar[i].x, ar[i].z, ar[i].y));
			bricks.pb(brick(ar[i].y, ar[i].z, ar[i].x));
		}

		sort(bricks.begin(), bricks.end(), comp);

		ll dp[bricks.size()];
		for(ll i=0; i<bricks.size(); i++)
			dp[i] = bricks[i].z;

		for(ll i=bricks.size()-1; i>0; i--)
		{

			for(ll j=i-1; j>=0; j--)
			{
				if(bricks[j].x>bricks[i].x && bricks[j].y>bricks[i].y && dp[j]<dp[i]+bricks[j].z)
					dp[j] = dp[i] + bricks[j].z;
			}

		}

		ll max = 0;
		for(ll i=0; i<bricks.size(); i++)
			if(dp[i]>max)
				max = dp[i];

		cout<<max<<endl;
		cin>>n;
	}
	return 0;
}
