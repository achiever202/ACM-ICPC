#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

#define mod 1000000007
#define ll long long int
#define maxn 10000
#define pb push_back
#define seive_max 10000

using namespace std;

class songs
{
	public:
		ll length;
		ll band;

}ar[100005];

bool comp(songs i, songs j)
{
	if(i.band==j.band)
		return i.length<j.length;
	else
		return i.band<j.band;
}

ll min_l[100005];

int main()
{
	ll t, n, k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(ll i=0; i<n; i++)
		{
			cin>>ar[i].band>>ar[i].length;
		}

		sort(ar, ar+n, comp);

		ll pos = 0;
		ll cur = -1;
		ll sum = 0;

		for(ll i=0; i<n; i++)
		{
			if(ar[i].band==cur)
				sum += ar[i].length;
			else
			{
				cur = ar[i].band;
				min_l[pos] = ar[i].length;
				pos++;
			}
		}

		sort(min_l, min_l+pos);

		sum *= pos;

		for(ll i=0; i<pos; i++)
		{
			sum += (i+1)*min_l[i];
		}

		cout<<sum<<endl;
	}
	return 0;
}
