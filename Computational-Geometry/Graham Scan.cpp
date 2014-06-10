#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <math.h>
 
#define mod 1000000007
#define ll long long int
#define maxn 5005
#define seive_max 35000
 
#define pb push_back
#define fact_max 5005
 
using namespace std;

class point
{
	public:
		ll x;
		ll y;

		point(ll i, ll j)
		{
			x = i;
			y = j;
		}

		point()
		{

		}

}points[1000];

point lowest_point;

/* This function returns the signed area of the triangle formed by the three points in order.
 * If it returns 0, the points are collinear.
 * If it returns positive, the points make a left turn.
 * Else, they take a right turn
 */
ll calculate_turn(point i, point j, point k)
{
	return (j.x-i.x)*(k.y-i.y) - (j.y-i.y)*(k.x-i.x);
}

/* This function calculates the lowest point in the given set */
void calc_lowest(ll n)
{
	lowest_point = points[0];
	for(ll i=1; i<n; i++)
	{
		if(points[i].y<lowest_point.y || (points[i].y==lowest_point.y && points[i].x<lowest_point.x))
			lowest_point = points[i];
	}
}

/* comp function to sort the points on their polar angle */
bool comp(point i, point j)
{
	ll area = calculate_turn(lowest_point, i, j);

	// collinear points.
	if(area==0)
	{
		ll dis1 = (i.x - lowest_point.x)*(i.x - lowest_point.x) + (i.y - lowest_point.y)*(i.y - lowest_point.y);
		ll dis2 = (j.x - lowest_point.x)*(j.x - lowest_point.x) + (j.y - lowest_point.y)*(j.y - lowest_point.y);

		return dis1<dis2;
	}
	else if(area>0)
		return true;
	else
		return false;
}

int main()
{
	ll t;
	point first, second, third;
	//cin>>t;
	t = 1;
	while(t--)
	{
		ll n;
		cin>>n;
		for(ll i=0; i<n; i++)
			cin>>points[i].x>>points[i].y;

		calc_lowest(n);
		sort(points, points+n, comp);

		points[n] = points[0];

		vector <point> graham;

		graham.push_back(points[0]);
		graham.push_back(points[1]);

		// pushing the points on the stack.
		// checking until the points make a left turn.
		ll pos = 2;
		ll size = 2;
		while(!(points[pos].x==lowest_point.x && points[pos].y==lowest_point.y))
		{
			graham.push_back(points[pos]);

			bool ctr = true;
			size++;

			while(size>2 && ctr)
			{
				third = graham[size-1];
				second = graham[size-2];
				first = graham[size-3];

				ll area = calculate_turn(first, second, third);
				if(area<=0)
				{
					point temp = graham[size-1];
					graham.pop_back();
					size--;
					graham.pop_back();
					graham.push_back(temp);

				}
				else
				{
					ctr = false;
				}
			}
			pos++;
		}

		graham.push_back(lowest_point);
		size++;

		double fence = 0;
		for(ll i=1; i<size; i++)
		{
			double dis = (graham[i].x - graham[i-1].x)*(graham[i].x - graham[i-1].x) + (graham[i].y - graham[i-1].y)*(graham[i].y - graham[i-1].y);
			fence += pow(dis, 0.5);
		}

		ll temp = fence;
		if(fence-temp>=0.5)
			cout<<temp+1<<endl;
		else
			cout<<temp<<endl;
	}
	return 0;
}
