/*
 * Algorithm: Z (To find the longest substring at an index that is also a prefix).
 * Complexity: O(n)
 * 
 * Tutorial: http://codeforces.com/blog/entry/3107
 *			 https://www.cs.umd.edu/class/fall2011/cmsc858s/Lec02-zalg.pdf
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
#include <cassert>
#include <math.h>

#define max_nodes_size 2000000
#define max_size 1002000
#define ll long long int unsigned
#define mod 1000000007

#define sd(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define w(t) while(t--)
#define fi(i,n) for(ll i=0; i<n; i++)
#define fd(i,n) for(ll i=n; i>=0; i--)
#define pb push_back
#define pl pair<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define f first
#define s second

using namespace std;

/* 
 * This function calculates the z_vector for a string.
 * @parameter p: the string for which the prefixes have to be found.
 * @return z_vector: the corresponding z vector.
 */
vl z_algprithm(string p)
{
	vl z_vector;
	z_vector.push_back(-1);
	ll l = 0, r = 0;
	for(ll i=1; i<p.length(); i++)
	{
		if(i>r)
		{
			l = i;
			r = i;
			while(r<p.length() && p[r-l]==p[r])
				r++;

			z_vector.push_back(r-l);
			r--;
		}
		else
		{
			ll k = i-l;
			if(z_vector[k]<r-l+1)
				z_vector.push_back(z_vector[k]);
			else
			{
				l = i;
				while(r<n && p[r-l]==p[r])
					r++;

				z_vector.push_back(r-l);
				r--;
			}
		}
	}

	return z_vector;
}
