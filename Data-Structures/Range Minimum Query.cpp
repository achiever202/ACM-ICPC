#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define mod 1000000007
#define ll long long int
#define maxn 1000005
#define seive_max 10000

#define pb push_back

using namespace std;

ll ar[10000005] = {0};
ll root_ar[10000] = {0};
ll max_root_ar[10000] = {0};

int main()
{
	ll n, m, a, b, c;
	cin>>n>>m;
	ll root = pow(n, 0.5);

	ll total_blocks = n/root;
	if(!(n%root==0))
		total_blocks++;

	while(m--)
	{
		cin>>a>>b>>c;
		a--; b--;

		ll first_slot = a/root;
		ll last_slot = b/root;

		ll first_left = a - first_slot*root;
		ll last_left = b - last_slot*root;

		if(first_left>0)
		{
			for(ll i=a; i<=b && i<(first_slot+1)*root; i++)
			{
				ar[i] += c;
				if(ar[i]>max_root_ar[first_slot])
					max_root_ar[first_slot] = ar[i];
			}
			first_slot++;
		}

		if(last_left<root-1)
		{
			if(last_slot>=first_slot)
			{
				for(ll i=b; i>=last_slot*root; i--)
				{
					ar[i] += c;
					if(ar[i]>max_root_ar[last_slot])
						max_root_ar[last_slot] = ar[i];
				}
			}
			last_slot--;
		}

		for(ll i=first_slot; i<=last_slot; i++)
			root_ar[i] += c;
	}

	ll max = 0;

	for(ll i=0; i<total_blocks; i++)
	{
		if(max<root_ar[i]+max_root_ar[i])
			max = root_ar[i] + max_root_ar[i];
	}
	cout<<max;
	return 0;
}
